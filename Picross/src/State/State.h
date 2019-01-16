#ifndef STATE_BASE_H
#define STATE_BASE_H
#include <memory>

#include "../Renderer/Renderer.h"
#include "../Layer/LayerStack.h"
#include "../Event/Event.h"

class Application;

class State
{
protected:
	std::unique_ptr<Renderer> m_Renderer;

	LayerStack m_LayerStack;

public:
	State()	: m_Renderer(std::make_unique<Renderer>()) {}
	virtual ~State() {}

	virtual void Pause() {};
	virtual void Resume() {};

	virtual bool OnEvent(EventEngine::Event& e)		= 0;
	virtual void OnUpdate(EventEngine::Event& e)	= 0;
	virtual void Render()							= 0;

	virtual void ChangeState(Application* app, State* state) = 0;
};

#endif