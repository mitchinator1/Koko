#ifndef GAME_H
#define GAME_H
#include <memory>
#include <vector>
#include <string>

namespace State { class StateBase; }

struct Display;
class Renderer;

class GameEngine
{
public:
	std::shared_ptr<Display> s_Display;
	std::unique_ptr<Renderer> m_Renderer;

	std::vector<std::unique_ptr<State::StateBase>> m_States;

	bool m_Running;

public:
	GameEngine(const std::string& title, float width, float height);
	~GameEngine();

	bool Init();

	void ChangeState(std::unique_ptr<State::StateBase> state);
	void PushState(std::unique_ptr<State::StateBase> state);
	void PopState();

	void HandleEvents();
	void Update();
	void Render();

	void Quit();

	inline auto IsRunning()		{ return m_Running; }
	inline auto& GetDisplay()	{ return s_Display; }
};

#endif