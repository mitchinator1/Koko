#include "GameLayer.h"

#include "State/State.h"

GameLayer::GameLayer()
	{

	}

GameLayer::~GameLayer()
{

}

void GameLayer::OnAttach()
{
	CalculateMesh();
}

void GameLayer::OnUpdate()
{
	CalculateMesh();
}

void GameLayer::OnEvent(Koko::Event& e)
{
	Koko::EventDispatcher dispatcher(e);
	dispatcher.Dispatch<Koko::MouseMovedEvent>(BIND_EVENT_FN(GameLayer::OnMouseMovedEvent));
	dispatcher.Dispatch<Koko::MouseButtonPressedEvent>(BIND_EVENT_FN(GameLayer::OnMouseButtonPressedEvent));
}

void GameLayer::Notify(Koko::State* state)
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

bool GameLayer::OnMouseMovedEvent(Koko::MouseMovedEvent& e)
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

bool GameLayer::OnMouseButtonPressedEvent(Koko::MouseButtonPressedEvent& e)
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