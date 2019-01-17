#include "Application.h"
#include "State/MenuState.h"

int main()
{
	auto Game = new Application;
	Game->GetState().PushState(new MenuState());

	Game->Run();

	delete Game;

	return 0;
}
