#include "Koko.h"
#include "State/MenuState.h"

#include <string>

int main()
{
	//Include proper files in Koko.h
	auto Game = new Koko::Application;
	Game->GetState().Push(new MenuState("Menu"));

	Game->Run();

	delete Game;

	return 0;
}
