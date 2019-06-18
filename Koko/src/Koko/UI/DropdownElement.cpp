#include "kkpch.h"
#include "DropdownElement.h"

namespace Koko
{
	Dropdown::Dropdown()
	{
		m_Flag.Enable(KK_UPDATENEEDED);
	}

	Dropdown::~Dropdown()
	{

	}

	void Koko::Dropdown::OnUpdate()
	{
		for (auto& element : m_Elements)
		{
			element->GetState().Disable(KK_UPDATENEEDED);
		}

		m_Flag.Disable(KK_UPDATENEEDED);
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
			if (e->GetState().Check(KK_HIDDEN))
			{
				continue;
			}

			auto& v = e->GetVertices();
			vertices.insert(vertices.end(), v.begin(), v.end());
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
			e->ToParentPosition(X, Y, Z);
		}
	}
	
	void Dropdown::AddElement(Element* e)
	{
		m_Elements.emplace_back(e);
	}

	bool Dropdown::InHitbox(float x, float y)
	{
		//Check if Parent is selected
		if (x >= X && x <= X + Width && y >= Y && y <= Y + Height)
		{
			if (!m_Flag.Check(KK_SELECTED))
			{
				m_Flag.Enable(KK_SELECTED | KK_UPDATENEEDED);
			}

			for (auto& element : m_Elements)
			{
				if (element->GetState().Check(KK_HIDDEN))
				{
					element->GetState().Disable(KK_HIDDEN);
				}
			}
			return true;
		}

		//If parent isn't selected, children might be
		for (auto& element : m_Elements)
		{
			if (element->InHitbox(x, y))
			{
				if (!element->GetState().Check(KK_SELECTED))
				{
					element->GetState().Enable(KK_SELECTED | KK_UPDATENEEDED);
				}
				return true;
			}
		}

		//Nothing selected
		for (auto& element : m_Elements)
		{
			element->GetState().Enable(KK_HIDDEN);
			element->GetState().Disable(KK_SELECTED);
		}

		if (m_Flag.Check(KK_SELECTED))
		{
			m_Flag.Enable(KK_UPDATENEEDED);
			m_Flag.Disable(KK_SELECTED);
		}
		return false;
	}
}
