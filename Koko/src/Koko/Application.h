#ifndef APPLICATION_H
#define APPLICATION_H
#include "Core.h"
#include "Window.h"
#include "Koko/State.h"

namespace Koko
{
	class State;
	class WindowCloseEvent;

	class KK_API Application
	{
	public:
		std::unique_ptr<Window> m_Window;

		std::vector<State*> m_States;

		bool m_Running = true;

		static Application* s_Instance;

	public:
		Application();
		~Application();

		void Run();

		void OnEvent(Event& e);
		void Render();

		void PushState(State* state) { m_States.emplace_back(state); }

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

		inline static void Quit() { s_Instance->m_Running = false; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

#endif