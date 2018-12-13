#include "GameEngine.h"

int main()
{
	auto Game = std::make_unique<GameEngine>("Picross", 1800.0f, 1400.0f);
	if (!Game->Init())
	{
		std::cout << "Game not initialized.\n";
	}

	while (Game->IsRunning())
	{
		Game->HandleEvents();
		Game->Update();
		Game->Render();
	}

	return 0;
}
