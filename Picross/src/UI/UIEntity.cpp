#include "UIEntity.h"
#include "Event/MouseEvent.h"

bool UIEntity::OnMouseMovedEvent(EventEngine::MouseMovedEvent& e)
{
	if (InHitbox(e.GetX(), e.GetY()))
	{
		mouseOver = true;
		return true;
	}
	else if (mouseOver)
	{
		mouseOver = false;
	}

	 return false;
}

bool UIEntity::OnMouseButtonPressedEvent(EventEngine::MouseButtonPressedEvent& e)
{
	if (mouseOver)
	{
		return true;
	}

	return false;
}