#ifndef APPLICATION_H
#define APPLICATION_H
#include "Core.h"

#include "Event/ApplicationEvent.h"
#include "Event/KeyEvent.h"

#include "Window.h"

#include "Utility/Stack.h"
#include "State/State.h"

namespace Koko
{
	class KK_API Application
	{
	public:
		std::unique_ptr<Window> m_Window;
		Stack<Koko::State> m_StateStack;

		bool m_Running = true;

		static Application* s_Instance;

	public:
		Application();
		~Application();

		void Run();

		void Render();

		void OnEvent(Event& e);

		auto& GetState() { return m_StateStack; }

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnKeyEvent(KeyPressedEvent& e);
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

#endif