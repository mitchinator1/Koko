#ifndef APPLICATION_H
#define APPLICATION_H
#include <memory>
#include <vector>

#include "Event/ApplicationEvent.h"
#include "Event/KeyEvent.h"

#include "Platform/Window.h"

#include "Utility/Stack.h"
#include "State/State.h"

class Application
{
public:
	std::unique_ptr<Window> m_Window;
	Stack<State> m_StateStack;

	bool m_Running;

public:
	Application();
	~Application();

	void Run();

	void Render();

	void OnEvent(EventEngine::Event& e);

	auto& GetState() { return m_StateStack; }

private:
	bool OnWindowClose(EventEngine::WindowCloseEvent& e);
	bool OnKeyEvent(EventEngine::KeyPressedEvent& e);
};

#endif