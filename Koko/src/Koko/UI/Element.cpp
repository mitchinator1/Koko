#include "kkpch.h"
#include "Element.h"

namespace Koko
{
	void Element::OnUpdate()
	{
		m_Flag.Disable(KK_UPDATENEEDED);
	}

	std::vector<float> Element::CalculateVertices()
	{
		float y = 100.0f - Y;
		float w = X + Width;
		float h = y - Height;

		return std::vector<float>({
			X, y, Z, R, G, B, A,
			X, h, Z, R, G, B, A,
			w, h, Z, R, G, B, A,
			w, y, Z, R, G, B, A
			});
	}

	void Element::ToParentPosition(float x, float y, float z)
	{
		X += x;
		Y += y;
		Z += z;
	}

	bool Element::InHitbox(float x, float y)
	{
		if (m_Flag.Check(KK_HIDDEN))
		{
			return false;
		}

		return (x >= X && x <= X + Width &&	y >= Y && y <= Y + Height);
	}
}