#include "kkpch.h"
#include "DropdownElement.h"

namespace Koko
{
	Dropdown::Dropdown()
	{
		Koko::Element element;
		element.X = 0.0f;
		element.Y = 15.0f;
		element.Z = 0.0f;
		element.Width = 15.0f;
		element.Height = 15.0f;
		element.R = 19.0f;
		element.G = 13.0f;
		element.B = 85.0f;
		element.A = 100.0f;

		AddElement(element);
	}

	void Koko::Dropdown::OnUpdate()
	{

	}

	std::vector<float> Dropdown::CalculateVertices()
	{
		float y = 100.0f - Y;
		float w = X + Width;
		float h = y - Height;

		std::vector<float> vertices({
			X, y, Z, R, G, B, A,
			X, h, Z, R, G, B, A,
			w, h, Z, R, G, B, A,
			w, y, Z, R, G, B, A
			});

		for (auto& e : m_Elements)
		{
			if (!e.IsHidden())
			{
				auto& v = e.GetVertices();
				vertices.insert(vertices.end(), v.begin(), v.end());
			}
		}
		return vertices;
	}

	void Dropdown::ToParentPosition(float x, float y, float z)
	{
		X += x;
		Y += y;
		Z += z;

		for (auto& e : m_Elements)
		{
			e.ToParentPosition(X, Y, Z);
		}
	}
	
	void Dropdown::AddElement(Element& e)
	{
		m_Elements.emplace_back(e);
	}

	bool Dropdown::InHitbox(float x, float y)
	{
		if (x >= X && x <= X + Width &&
			y >= Y && y <= Y + Height)
		{
			return true;
		}

		for (auto& element : m_Elements)
		{
			if (element.IsHidden())
			{
				continue;
			}

			if (element.InHitbox(x, y))
			{
				return true;
			}
		}

		return false;
	}
}
