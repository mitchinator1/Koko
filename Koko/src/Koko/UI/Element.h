#ifndef ELEMENT_H
#define ELEMENT_H

#include "Koko/Entity/Flag.h"

namespace Koko
{
	class Element
	{
	public:
		float X = 0.0f, Y = 0.0f, Z = 0.0f;
		float Width = 0.0f, Height = 0.0f;
		float R = 0.0f, G = 0.0f, B = 0.0f, A = 0.0f;

	protected:
		Flag m_Flag;

	public:
		virtual ~Element() {}
		virtual void OnUpdate();

		virtual std::vector<float> CalculateVertices();
		virtual void ToParentPosition(float x, float y, float z = 0.0f);

		virtual std::vector<float> GetVertices() { return CalculateVertices(); }

		virtual bool InHitbox(float x, float y);

		inline auto& GetState() { return m_Flag; }
		
	};

}

#endif