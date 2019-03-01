#include "Koko.h"
#include "Koko/State/MenuState.h"

int main()
{
	auto Game = new Koko::Application;
	Game->GetState().Push(new Koko::MenuState());

	Game->Run();

	delete Game;

	return 0;
}
