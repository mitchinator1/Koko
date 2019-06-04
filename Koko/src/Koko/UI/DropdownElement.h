#ifndef DROPDOWN_ELEMENT_H
#define DROPDOWN_ELEMENT_H
#include "Element.h"

namespace Koko
{
	class Dropdown : public Element
	{
	private:
		std::vector<Element> m_Elements;

	public:
		Dropdown();
		void OnUpdate() override;

		std::vector<float> CalculateVertices()		override;
		virtual std::vector<float> GetVertices()	override { return CalculateVertices(); }
		virtual void ToParentPosition(float x, float y, float z = 0.0f);

		void AddElement(Element& e);

		bool InHitbox(float x, float y) override;
	};
}

#endif