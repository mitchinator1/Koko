#ifndef MENU_STATE_H
#define MENU_STATE_H
#include <string>
#include "Koko/State/State.h"

class MenuState : public Koko::State
{
private:
	Mesh* m_TextMesh = nullptr;

public:
	MenuState(const std::string& fileName = "Menu");
	~MenuState();

	bool OnEvent(Koko::Event& e)		override;
	void OnUpdate(Koko::Event& e)		override;
	void Render()						override;

	void Notify(Stack<State>* stack)		override;
	void NotifyLayers()						override;
	void ReceiveAction(Action action)		override;
};

#endif