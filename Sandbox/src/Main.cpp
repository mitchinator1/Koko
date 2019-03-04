#include "Koko.h"
#include "State/MenuState.h"

int main()
{
	//TODO: Break menu state out to Sandbox
	//Include proper files in Koko.h
	auto Game = new Koko::Application;
	Game->GetState().Push(new MenuState("Menu"));

	Game->Run();

	delete Game;

	return 0;
}
