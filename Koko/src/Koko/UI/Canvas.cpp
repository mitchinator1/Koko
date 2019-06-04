#include "kkpch.h"
#include "Koko/Core.h"
#include "Canvas.h"

#include "Koko/Event/Event.h"
#include "Koko/Event/MouseEvent.h"

namespace Koko
{
	Canvas::Canvas(float x, float y, float width, float height)
		: m_Mesh(nullptr)
		, X(x), Y(y), Width(100.0f), Height(100.0f)
	{

	}

	void Canvas::OnUpdate()
	{
		for (auto& e : m_Elements)
		{
			e->OnUpdate();
		}
		CreateMesh();
	}

	void Canvas::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(Canvas::OnMouseMovedEvent));
		dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(Canvas::OnMouseButtonPressedEvent));
	}

	void Canvas::AddElement(Element* e)
	{
		e->ToParentPosition(X, Y);
		m_Elements.emplace_back(e);
		CreateMesh();
	}

	void Canvas::RemoveElement(Element* e)
	{

	}

	std::vector<float> Canvas::ToScreenSpace(std::vector<float>& vertices)
	{
		for (auto& point : vertices)
		{
			point = point / 50.0f - 1.0f;
		}

		return vertices;
	}

	void Canvas::CreateMesh()
	{
		std::vector<float> vertices;
		for (auto& e : m_Elements)
		{
			if (e->IsHidden())
			{
				continue;
			}
			auto& v = e->GetVertices();
			vertices.insert(vertices.end(), v.begin(), v.end());
		}

		if (!m_Mesh)
		{
			m_Mesh = std::make_unique<Mesh>(ToScreenSpace(vertices));
		}
		else
		{
			m_Mesh->UpdateVertices(ToScreenSpace(vertices));
		}
	}

	bool Canvas::OnMouseMovedEvent(MouseMovedEvent& e)
	{
		bool hit = false;

		for (auto element : m_Elements)
		{
			if (element->IsHidden())
			{
				continue;
			}

			if (element->InHitbox(e.GetX(), e.GetY()))
			{
				hit = true;
				std::cout << "Hit Detected.\n";
			}
		}

		return hit;
	}

	bool Canvas::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
	{
		return false;
	}
}