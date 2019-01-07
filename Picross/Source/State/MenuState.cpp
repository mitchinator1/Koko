#include "MenuState.h"
#include "../Entity/EntityBase.h"

#include "../Event/MouseEvent.h"
#include "../Application.h"
#include "../UILayer.h"

#define BIND_EVENT_FN(x) std::bind(&MenuState::x, this, std::placeholders::_1)

MenuState::MenuState()
{
	//TODO: Display and handling order is by add-order, not depth-order
	UILayer* ui2 = new UILayer();
	ui2->PushEntity(new Entity::EntityBase(30.0f, 30.0f, 15.0f, 10.0f));
	m_LayerStack.PushOverlay(ui2);

	UILayer* ui1 = new UILayer();
	ui1->PushEntity(new Entity::EntityBase(40.0f, 35.0f, 15.0f, 10.0f, 50.0f, 60.0f, 70.0f));
	m_LayerStack.PushLayer(ui1);
}

MenuState::~MenuState()
{

}

bool MenuState::OnEvent(EventEngine::Event& e)
{
	using namespace EventEngine;
	Dispatcher dispatcher(e);

	//TODO: Needs Tidying
	dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(OnMouseMovedEvent));
	dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(OnMouseButtonPressedEvent));

	return true;
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

bool MenuState::OnMouseMovedEvent(EventEngine::MouseMovedEvent& e)
{
	//TODO: Messy, just testing. tidying up.
	auto x = e.GetX();
	auto y = e.GetY();

	auto& layers = m_LayerStack.GetLayer();

	bool hit = false;

	for (int it = m_LayerStack.GetLayer().size() - 1; it >= 0; --it)
	{
		auto& layer = m_LayerStack.GetLayer()[it];

		for (auto entity : layer->GetEntities())
		{

			if (x >= entity->x && x <= entity->x + entity->width &&
				y >= entity->y && y <= entity->y + entity->height)
			{
				entity->mouseOver = true;
				hit = true;
				break;
			}
			if (entity->mouseOver)
			{
				entity->mouseOver = false;
			}

			if (hit)
			{
				break;
			}
		}
	}
	
	return hit;
}

bool MenuState::OnMouseButtonPressedEvent(EventEngine::MouseButtonPressedEvent& e)
{
	for (int it = m_LayerStack.GetLayer().size() - 1; it >= 0; --it)
	{
		auto& layer = m_LayerStack.GetLayer()[it];

		for (auto entity : layer->GetEntities())
		{
			if (entity->mouseOver)
			{
				//TODO: Set entity handling up
				layer->PopEntity(entity);
				layer->OnUpdate();
				return true;
			}
		}
	}

	return false;
}