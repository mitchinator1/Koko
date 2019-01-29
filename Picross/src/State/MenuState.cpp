#include "MenuState.h"

#include "../Application.h"

#include "../Layer/UILayer.h"
#include "../Layer/LayerBuilder.h"

MenuState::MenuState()
{
	LayerBuilder builder("Menu");
	builder.Build(m_LayerStack);
}

MenuState::~MenuState()
{

}

bool MenuState::OnEvent(EventEngine::Event& e)
{
	for (auto layer : m_LayerStack)
	{
		layer->OnEvent(e);
		if (e.Handled)
		{
			return true;
		}
	}

	return false;
}

void MenuState::OnUpdate(EventEngine::Event& e)
{
	
}

void MenuState::Render()
{
	m_Renderer->Render(m_LayerStack);
}

void MenuState::ChangeState(Application* app, State* state)
{
	app->GetState().ChangeState(state);
}