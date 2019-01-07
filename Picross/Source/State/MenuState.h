#ifndef STATE_MENU_H
#define STATE_MENU_H
#include "State.h"
#include "../Event/MouseEvent.h"

namespace Entity { class EntityBase; }

class MenuState : public State
{
private:
	std::vector<Entity::EntityBase> m_Entities;

public:
	MenuState();
	~MenuState();

	bool OnEvent(EventEngine::Event& e)		override;
	void OnUpdate(EventEngine::Event& e)	override;
	void Render()		override;

	void ChangeState(Application* app, State* state)	override;

private:
	bool OnMouseMovedEvent(EventEngine::MouseMovedEvent& e);
	bool OnMouseButtonPressedEvent(EventEngine::MouseButtonPressedEvent& e);
};

#endif