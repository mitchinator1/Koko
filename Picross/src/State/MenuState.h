#ifndef STATE_MENU_H
#define STATE_MENU_H
#include "State.h"
#include "../Event/MouseEvent.h"

class MenuState : public State
{
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