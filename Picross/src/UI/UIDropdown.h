#ifndef UI_DROPDOWN_H
#define UI_DROPDOWN_H
#include "UIEntity.h"

class UIDropdown : public UIEntity
{
public:
	~UIDropdown();

	std::vector<float> GetVertices() override;

	bool OnMouseMovedEvent(EventEngine::MouseMovedEvent& e) override;
	bool OnMouseButtonPressedEvent(EventEngine::MouseButtonPressedEvent& e) override;

private:
	bool Reveal();
	bool Hide();

};

#endif