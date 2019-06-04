#include "kkpch.h"
#include "Application.h"

#include "Event/ApplicationEvent.h"
#include "Event/KeyEvent.h"

namespace Koko
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
		: m_Running(true)
	{
		s_Instance = this;

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
			m_StateStack.back()->OnUpdate();

			Render();
			m_Window->OnUpdate();
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
		return false;
	}

}