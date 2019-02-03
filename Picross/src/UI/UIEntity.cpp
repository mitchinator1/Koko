#include "UIEntity.h"
#include "Event/MouseEvent.h"

bool UIEntity::OnMouseMovedEvent(EventEngine::MouseMovedEvent& e)
{
	if (InHitbox(e.GetX(), e.GetY()))
	{
		state = State::Selected;
		return true;
	}
	else if (state == State::Selected)
	{
		state = State::None;
	}

	 return false;
}

bool UIEntity::OnMouseButtonPressedEvent(EventEngine::MouseButtonPressedEvent& e)
{
	if (state == State::Selected)
	{
		state = State::Remove;
		return true;
	}

	return false;
}

void UIEntity::AddEntity(Entity* entity)
{
	m_Entities.emplace_back(entity);
	state = State::Update;
}

void UIEntity::PopEntity(Entity* entity)
{
	auto it = std::find(m_Entities.begin(), m_Entities.end(), entity);
	if (it != m_Entities.end())
	{
		m_Entities.erase(it);
		state = State::Update;
	}
}