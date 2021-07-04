#ifndef ENTITY_H
#define ENTITY_H
#include "kkpch.h"
#include "Koko/Core.h"
#include "Koko/Events/Action.h"

#include "EntityComponent.h"
#include "Flag.h"

#include "Koko/Text.h"

namespace Koko
{
	class MouseMovedEvent;
	class MouseButtonPressedEvent;

	class /*KK_API*/ Entity
	{
	public:
		//TODO: Fix horrible name
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
		Flag m_Flag;

		Action action = Action::None;
		Action mousePress = Action::None;

		//Todo: Make vertices seperate class with vertices data, stride, and count.
		//include with mesh, can pass vertices class to mesh

	private:
		Text* m_Text = nullptr;

	public:
		Entity() { m_Flag.Enable(KK_UPDATENEEDED); }
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
			float z = position.z;
			float w = x + size.width;
			float h = y - size.height;

			return std::vector<float>({
				x,	y,	z,		colour.r, colour.g, colour.b, colour.a,
				x,	h,	z,		colour.r, colour.g, colour.b, colour.a,
				w,	h,	z,		colour.r, colour.g, colour.b, colour.a,
				w,	y,	z,		colour.r, colour.g, colour.b, colour.a
				});
		}

		virtual void OnUpdate() {}

		virtual bool OnMouseMovedEvent(MouseMovedEvent& e) { return false; }
		virtual bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e) { return false; }

		virtual bool InHitbox(float x, float y)
		{
			if (m_Flag.Check(KK_HIDDEN))
			{
				return false;
			}

			return (x >= position.x && x <= position.x + size.width &&
				y >= position.y && y <= position.y + size.height);
		}

		virtual Action GetMousePress() { return mousePress; }

		virtual void SetText(Text* text)
		{
			auto& data = text->GetData();
			data.X = position.x;
			data.Y = position.y + (data.Size * 2.0f);
			data.Z = position.z;
			m_Text = text;
		}
		virtual Text* GetText()
		{
			if (!m_Text)
			{
				return m_Text;
			}

			if (!m_Text->IsCreated())
			{
				m_Text->CreateMesh();
			}

			return m_Text;
		}

	protected:
		std::vector<float> ToViewportSpace(std::vector<float>& vertices)
		{
			for (auto& point : vertices)
			{
				point = point / 50.0f - 1.0f;
			}

			return vertices;
		}

	};

}

#endif