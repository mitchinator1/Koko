#ifndef APPLICATION_H
#define APPLICATION_H
#include "Koko/Core/Core.h"

#include "Koko/Core/Window.h"
#include "Koko/Core/LayerStack.h"
#include "Koko/Events/Event.h"
#include "Koko/Events/ApplicationEvent.h"

#include "Koko/Core/Timestep.h"

#include "Koko/ImGui/ImGuiLayer.h"

namespace Koko
{

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

		inline LayerStack* GetLayerStack() { return &m_LayerStack; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

#endif