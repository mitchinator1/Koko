#include "StateMenu.h"
#include "../Mesh/Mesh.h"
#include "../Entity/EntityBase.h"

#include "../Input/Mouse.h"

namespace State
{
	StateMenu::StateMenu(std::shared_ptr<Display>& display)
		: StateBase(display)
		, m_Mouse(std::make_unique<Input::Mouse>(display))
	{
		Entity::EntityBase entity(20.0f, 20.0f, 10.0f, 10.0f);

		m_Mesh = new Mesh(entity.GetVertices());
	}

	StateMenu::~StateMenu()
	{

	}
	
	void StateMenu::HandleEvents(GameEngine* game)
	{
		//m_UI->HandleEvents(m_Display);
		m_Mouse->GetInput();

		if (glfwGetKey(s_Display->Window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(s_Display->Window))
			game->Quit();
	}

	void StateMenu::Update(GameEngine* game)
	{
		if ((m_Mouse->x >= 20.0f) && (m_Mouse->x <= 30.0f) &&
			(m_Mouse->y >= 20.0f) && (m_Mouse->y <= 30.0f))
		{
			std::cout << "Entity is in range\n";
		}
	}

	void StateMenu::Render() const
	{
		m_Renderer->Render(m_Mesh);
	}
}