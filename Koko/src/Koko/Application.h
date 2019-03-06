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
	class Application
	{
	public:
		std::unique_ptr<Window> m_Window;
		Stack<Koko::State> m_StateStack;

		bool m_Running;

	public:
		KK_API Application();
		KK_API ~Application();

		KK_API void Run();

		KK_API void Render();

		KK_API void OnEvent(Event& e);

		KK_API auto& GetState() { return m_StateStack; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnKeyEvent(KeyPressedEvent& e);
	};

}

#endif