#include "GameEngine.h"

GameEngine::GameEngine(const std::string& title, float width, float height)
	: m_Running(false)
{
	glfwInit();
	m_Display = std::make_shared<Display>(title, width, height);
	m_Renderer = std::make_unique<Renderer>(m_Display);
}

GameEngine::~GameEngine()
{
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

	if (!m_Display->Init())
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

void GameEngine::HandleEvents()
{
	glfwPollEvents();

	if (glfwWindowShouldClose(m_Display->Window))
	{
		Quit();
	}
}

void GameEngine::Update()
{

}

void GameEngine::Render()
{
	m_Renderer->Render();
}

void GameEngine::Quit()
{
	glfwSetWindowShouldClose(m_Display->Window, true);
	m_Running = false;
}