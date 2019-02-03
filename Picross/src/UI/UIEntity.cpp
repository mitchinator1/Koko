#include "UIEntity.h"
#include "Event/MouseEvent.h"

std::vector<float> UIEntity::GetVertices()
{
	auto vertices = CalculateVertices();

	for (auto& entity : m_Entities)
	{
		if (entity->state == State::Hidden)
		{
			continue;
		}
		auto v = entity->CalculateVertices();
		vertices.insert(vertices.end(), v.begin(), v.end());
	}

	state = State::None;

	return ToViewportSpace(vertices);
}

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
	//Move entity relative to parent entity
	entity->position += position;

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

void UIEntity::SetState(State s)
{
	state = s;
}

void UIEntity::SetState(const std::string& s)
{
	if (s == "selected") state = State::Selected;
	if (s == "remove")	 state = State::Remove;
	if (s == "update")	 state = State::Update;
	if (s == "hidden")	 state = State::Hidden;
}