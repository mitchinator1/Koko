#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
#include "EntityComponent.h"
#include "Event/Action.h"

namespace EventEngine
{
	class MouseMovedEvent;
	class MouseButtonPressedEvent;
}

class Entity
{
public:
	enum class State
	{
		None = 0,
		Selected,
		Remove,
		Update,
		Hidden
	};

	Position position;
	Size size;
	Colour colour;
	State state = State::None;

	Action action = Action::None;
	Action mousePress = Action::None;

	//Todo: Make vertices seperate class with vertices data, stride, and count.
	//include with mesh, can pass vertices class to mesh

public:
	virtual ~Entity() {}

	virtual std::vector<float> GetVertices()
	{
		auto vertices = CalculateVertices();

		return ToViewportSpace(vertices);
	}
	std::vector<float> CalculateVertices()
	{
		float x = position.x;
		float y = 100.0f - position.y;
		float w = x + size.width;
		float h = y - size.height;
		
		float flipY = 100.0f - y;

		std::vector<float> vertices;

		vertices.insert(vertices.end(), {
			x,		y,	0.0f,		colour.r, colour.g, colour.b, colour.a,
			x,		h,	0.0f,		colour.r, colour.g, colour.b, colour.a,
			w,		h,	0.0f,		colour.r, colour.g, colour.b, colour.a,
			w,		y,	0.0f,		colour.r, colour.g, colour.b, colour.a
			});

		return vertices;
	}

	virtual bool OnMouseMovedEvent(EventEngine::MouseMovedEvent& e) { return false; }
	virtual bool OnMouseButtonPressedEvent(EventEngine::MouseButtonPressedEvent& e) { return false; }

	virtual bool InHitbox(float x, float y)
	{
		if (state == State::Hidden)
		{
			return false;
		}

		return (x >= position.x && x <= position.x + size.width &&
			y >= position.y && y <= position.y + size.height);
	}

	virtual Action GetMousePress() { return mousePress; }

protected:
	std::vector<float> ToViewportSpace(std::vector<float> vertices)
	{
		for (auto& point : vertices)
		{
			point = point / 50.0f - 1.0f;
		}

		return vertices;
	}

};

#endif