#ifndef DROPDOWN_ELEMENT_H
#define DROPDOWN_ELEMENT_H
#include "Element.h"

namespace Koko
{
	class Dropdown : public Element
	{
	private:
		std::vector<Element*> m_Elements;

	public:
		Dropdown();
		virtual ~Dropdown();

		void OnUpdate() override;

		virtual std::vector<float> CalculateVertices()					override;
		virtual void ToParentPosition(float x, float y, float z = 0.0f) override;
		virtual bool InHitbox(float x, float y)							override;

		void AddElement(Element* e);
	};
}

#endif