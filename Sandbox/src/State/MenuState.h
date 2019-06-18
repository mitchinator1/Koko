#ifndef MENU_STATE_H
#define MENU_STATE_H
#include <string>
#include "Koko/State.h"
#include "Koko/Entity/Flag.h"

namespace Koko { class Renderer; class Canvas; }

class MenuState : public Koko::State
{
private:
	bool remove = false;

	std::unique_ptr<Koko::Renderer> m_Renderer;

	std::unique_ptr<Koko::Canvas> m_Canvas;
	Koko::Flag m_Flag;

public:
	MenuState(const std::string& fileName = "Menu");
	~MenuState();

	void Pause()					override {}
	void Resume()					override {}

	bool OnEvent(Koko::Event& e)	override;
	void OnUpdate()					override;
	void Render()					override;
	
	//void Notify(Koko::Stack<State>* stack);
	//void NotifyLayers();
	//void ReceiveAction(Action action);
};

#endif