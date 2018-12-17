#include <memory>
#include "GameEngine.h"
#include "State/StateMenu.h"

int main()
{
	auto Game = std::make_unique<GameEngine>("Picross", 1800.0f, 1400.0f);
	Game->ChangeState(std::make_unique<State::StateMenu>(Game->GetDisplay()));

	while (Game->IsRunning())
	{
		Game->HandleEvents();
		Game->Update();
		Game->Render();
	}

	return 0;
}
