#include "Application.h"
#include "Event/MouseEvent.h"

#include "GLFW/glfw3.h"

Application::Application()
	: m_Running(true)
{
	m_Window = std::unique_ptr<Window>(Window::Create());
	m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
}

Application::~Application()
{

}

void Application::Run()
{
	while (m_Running)
	{
		m_Window->OnUpdate();
		Render();
	}
}

void Application::Render()
{
	m_StateStack.Back()->Render();
}

void Application::OnEvent(EventEngine::Event& e)
{
	m_StateStack.Back()->OnEvent(e);

	using namespace EventEngine;
	Dispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
	dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(Application::OnKeyEvent));

}

bool Application::OnWindowClose(EventEngine::WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}

bool Application::OnKeyEvent(EventEngine::KeyPressedEvent& e)
{
	if (e.GetKeyCode() == GLFW_KEY_ESCAPE)
	{
		m_Running = false;
		return true;
	}

	return false;
}