#include <Koko.h>
#include <Koko/Core/EntryPoint.h>

#include "Sandbox2D.h"

class Sandbox : public Koko::Application
{
public:
	Sandbox()
	{
		PushLayer(new Sandbox2D());
		//Next Episode: #64 Renderer Stats and Batch Improvements
		// Add ImGui
	}

	~Sandbox()
	{
	}
};

Koko::Application* Koko::CreateApplication()
{
	return new Sandbox();
}