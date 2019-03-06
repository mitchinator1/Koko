#include "UILayer.h"

#include "Koko/State/State.h"

UILayer::UILayer()
{

}

UILayer::~UILayer()
{

}

void UILayer::OnAttach()
{
	CalculateMesh();
}

void UILayer::OnUpdate()
{
	CalculateMesh();
}

void UILayer::OnEvent(Koko::Event& e)
{
	Koko::EventDispatcher dispatcher(e);
	dispatcher.Dispatch<Koko::MouseMovedEvent>(BIND_EVENT_FN(UILayer::OnMouseMovedEvent));
	dispatcher.Dispatch<Koko::MouseButtonPressedEvent>(BIND_EVENT_FN(UILayer::OnMouseButtonPressedEvent));
}

void UILayer::Notify(Koko::State* state)
{
	for (auto action : m_Actions)
	{
		if (action == Action::LayerRemove)
		{
			updatestate = Koko::Entity::State::Remove;
			continue;
		}
		state->ReceiveAction(action);
	}

	m_Actions.clear();
}

bool UILayer::OnMouseMovedEvent(Koko::MouseMovedEvent& e)
{
	bool hit = false;

	for (auto entity : m_Entities)
	{
		if (entity->OnMouseMovedEvent(e))
		{
			hit = true;
		}
		if (entity->state == Koko::Entity::State::Update)
		{
			CalculateMesh();
			entity->state = Koko::Entity::State::None;
		}
	}

	return hit;
}

bool UILayer::OnMouseButtonPressedEvent(Koko::MouseButtonPressedEvent& e)
{
	bool hit = false;
	//TODO: Pick left or right button
	for (auto entity : m_Entities)
	{
		if (entity->OnMouseButtonPressedEvent(e))
		{
			if (entity->state == Koko::Entity::State::Remove)
			{
				PopEntity(entity);
			}
			m_Actions.emplace_back(entity->GetMousePress());
			hit = true;
		}

		if (entity->state == Koko::Entity::State::Update)
		{
			CalculateMesh();
			entity->state = Koko::Entity::State::None;
		}
	}

	return hit;
}