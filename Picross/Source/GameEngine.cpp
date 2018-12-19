#include "GameEngine.h"
#include "Display.h"
#include "Renderer/Renderer.h"
#include "State/StateBase.h"

GameEngine::GameEngine(const std::string& title, float width, float height)
	: m_Running(false), s_Display(std::make_shared<Display>(title, width, height))
{
	if (!Init())
	{
		std::cout << "Error on Game Engine Init.\n";
	}

	
}

GameEngine::~GameEngine()
{
	while (!m_States.empty())
	{
		m_States.pop_back();
	}
	glfwTerminate();
}

bool GameEngine::Init()
{
	if (!glfwInit())
	{
		std::cout << "GLFW not initialized.\n";
		glfwTerminate();
		return false;
	}

	if (!s_Display->Init())
	{
		std::cout << "Window not created.\n";
		return false;
	}

	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW not initialized.\n";
		return false;
	}

	m_Running = true;

	return true;
}

void GameEngine::ChangeState(std::unique_ptr<State::StateBase> state)
{
	if (!m_States.empty())
		m_States.pop_back();

	m_States.emplace_back(std::move(state));
}

void GameEngine::PushState(std::unique_ptr<State::StateBase> state)
{
	if (!m_States.empty())
		m_States.back()->Pause();

	m_States.emplace_back(std::move(state));
}

void GameEngine::PopState()
{
	if (m_States.size() > 1)
		m_States.pop_back();

	if (!m_States.empty())
		m_States.back()->Resume();
}

void GameEngine::HandleEvents()
{
	glfwPollEvents();

	m_States.back()->HandleEvents(this);
}

void GameEngine::Update()
{
	m_States.back()->Update(this);
}

void GameEngine::Render()
{
	m_States.back()->Render();
}

void GameEngine::Quit()
{
	glfwSetWindowShouldClose(s_Display->Window, true);
	m_Running = false;
}