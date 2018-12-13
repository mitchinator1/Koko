#ifndef GAME_H
#define GAME_H
#include <memory>
#include "Display.h"
#include "Renderer/Renderer.h"

class GameEngine
{
public:
	std::shared_ptr<Display> m_Display;
	std::unique_ptr<Renderer> m_Renderer;
	bool m_Running;

public:
	GameEngine(const std::string& title, float width, float height);
	~GameEngine();

	bool Init();

	void HandleEvents();
	void Update();
	void Render();

	void Quit();

	inline auto IsRunning()		{ return m_Running; }
	inline auto& GetDisplay()	{ return m_Display; }
};

#endif