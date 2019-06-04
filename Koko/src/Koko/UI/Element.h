#ifndef ELEMENT_H
#define ELEMENT_H

namespace Koko
{
	class Element
	{
	public:
		float X, Y, Z;
		float Width, Height;
		float R, G, B, A;

	private:
		bool m_Hidden = false;

	public:
		virtual void OnUpdate();

		virtual std::vector<float> CalculateVertices();
		virtual void ToParentPosition(float x, float y, float z = 0.0f);

		virtual std::vector<float> GetVertices() { return CalculateVertices(); }

		virtual bool InHitbox(float x, float y);

		virtual bool IsHidden() { return m_Hidden; }

	};

	inline bool operator==(const Element& lhs, const Element& rhs)
	{
		return true;
	}
	inline bool operator!=(const Element& lhs, const Element& rhs)
	{
		return !(lhs == rhs);
	}
}

#endif