#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
#include "EntityComponent.h"

class Entity
{
public:
	Position position;
	Size size;
	Colour colour;

	bool mouseOver = false;

private:
	//std::vector<float> m_Vertices;
	//Todo: Make vertices seperate class with vertices data, stride, and count.
	//include with mesh, can pass vertices class to mesh

public:
	virtual ~Entity() {}

	std::vector<float> GetVertices()
	{
		auto vertices = CalculateVertices();

		return ToViewportSpace(vertices);
	}

protected:
	std::vector<float> ToViewportSpace(std::vector<float> vertices)
	{
		for (auto& point : vertices)
		{
			point = point / 50.0f - 1.0f;
		}

		return vertices;
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
};

#endif