#include "kkpch.h"
#include "Application.h"
#include "Event/MouseEvent.h"

#include "GLFW/glfw3.h"

namespace Koko
{
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
		if (!m_StateStack.empty())
		{
			m_StateStack.back()->Render();
		}
	}

	void Application::OnEvent(Koko::Event& e)
	{
		m_StateStack.back()->OnEvent(e);
		m_StateStack.Notify();

		if (m_StateStack.empty())
		{
			m_Running = false;
		}

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(Application::OnKeyEvent));
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnKeyEvent(KeyPressedEvent& e)
	{
		if (e.GetKeyCode() == GLFW_KEY_ESCAPE)
		{
			m_Running = false;
			return true;
		}

		return false;
	}

}