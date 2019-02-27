#ifndef APPLICATION_H
#define APPLICATION_H
#include "Core.h"

#include "Event/ApplicationEvent.h"
#include "Event/KeyEvent.h"

#include "Platform/Window.h"

#include "Utility/Stack.h"
#include "State/State.h"

class KK_API Application
{
public:
	std::unique_ptr<Window> m_Window;
	Stack<Koko::State> m_StateStack;

	bool m_Running;

public:
	Application();
	~Application();

	void Run();

	void Render();

	void OnEvent(Koko::Event& e);

	auto& GetState() { return m_StateStack; }

private:
	bool OnWindowClose(Koko::WindowCloseEvent& e);
	bool OnKeyEvent(Koko::KeyPressedEvent& e);
};

#endif