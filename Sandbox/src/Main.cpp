#include "Koko.h"

#include "State/MenuState.h"

class Sandbox : public Koko::Application
{
public:
	Sandbox()
	{
		GetState().Push(new MenuState("Menu"));
	}

	~Sandbox()
	{

	}

};

Koko::Application* Koko::CreateApplication()
{
	return new Sandbox();
}
