#ifndef UI_ENTITY_H
#define UI_ENTITY_H
#include "Entity/Entity.h"

class UIEntity : public Entity
{
public:
	bool OnMouseMovedEvent(EventEngine::MouseMovedEvent& e) override;
	bool OnMouseButtonPressedEvent(EventEngine::MouseButtonPressedEvent& e) override;

};

#endif