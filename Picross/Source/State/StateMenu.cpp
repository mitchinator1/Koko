#include "StateMenu.h"
#include "../Mesh/Mesh.h"
#include "../Entity/EntityBase.h"

namespace State
{
	StateMenu::StateMenu(std::shared_ptr<Display>& display)
		: StateBase(display)
	{
		Entity::EntityBase entity({
			20.0f, 20.0f, 0.0f,		80.0f, 40.0f, 50.0f, 100.0f,
			20.0f, 30.0f, 0.0f,		80.0f, 40.0f, 50.0f, 100.0f,
			30.0f, 30.0f, 0.0f,		80.0f, 40.0f, 50.0f, 100.0f,
			30.0f, 20.0f, 0.0f,		80.0f, 40.0f, 50.0f, 100.0f,
			});

		entity.AddVertices({
			40.0f, 40.0f, 0.0f,		80.0f, 40.0f, 50.0f, 100.0f,
			40.0f, 50.0f, 0.0f,		80.0f, 40.0f, 50.0f, 100.0f,
			50.0f, 50.0f, 0.0f,		80.0f, 40.0f, 50.0f, 100.0f,
			50.0f, 40.0f, 0.0f,		80.0f, 40.0f, 50.0f, 100.0f
			});
			

		m_Mesh = new Mesh(entity.GetVertices(),	{ 3, 4 });
	}

	StateMenu::~StateMenu()
	{

	}
	
	void StateMenu::HandleEvents(GameEngine* game)
	{
		//m_UI->HandleEvents(m_Display);

		if (glfwGetKey(m_Display->Window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(m_Display->Window))
			game->Quit();
	}

	void StateMenu::Update(GameEngine* game)
	{
		
	}

	void StateMenu::Render() const
	{
		m_Renderer->Render(m_Mesh);
	}
}