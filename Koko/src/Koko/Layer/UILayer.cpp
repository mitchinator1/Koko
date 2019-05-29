#include "kkpch.h"
#include "UILayer.h"

#include "Koko/State/State.h"

namespace Koko
{
	UILayer::UILayer()
	{
		std::cout << "UI Layer created\n";
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

	void UILayer::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(UILayer::OnMouseMovedEvent));
		dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(UILayer::OnMouseButtonPressedEvent));
	}

	void UILayer::Notify(State* state)
	{
		for (auto action : m_Actions)
		{
			if (action == Action::LayerRemove)
			{
				updatestate = Entity::State::Remove;
				continue;
			}
			state->ReceiveAction(action);
		}

		m_Actions.clear();
	}

	bool UILayer::OnMouseMovedEvent(MouseMovedEvent& e)
	{
		bool hit = false;

		for (auto entity : m_Entities)
		{
			if (entity->OnMouseMovedEvent(e))
			{
				hit = true;
			}
			if (entity->state == Entity::State::Update)
			{
				CalculateMesh();
				entity->state = Entity::State::None;
			}
		}

		return hit;
	}

	bool UILayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
	{
		bool hit = false;
		//TODO: Pick left or right button
		for (auto entity : m_Entities)
		{
			if (entity->OnMouseButtonPressedEvent(e))
			{
				if (entity->state == Entity::State::Remove)
				{
					PopEntity(entity);
				}
				m_Actions.emplace_back(entity->GetMousePress());
				hit = true;
			}

			if (entity->state == Entity::State::Update)
			{
				CalculateMesh();
				entity->state = Entity::State::None;
			}
		}

		return hit;
	}

}