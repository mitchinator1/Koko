#include "gepch.h"
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
		if (mousePress == Action::EntityRemove)
		{
			state = State::Remove;
		}
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
	if (s == "none")	 SetState(State::None);
	if (s == "selected") SetState(State::Selected);
	if (s == "remove")	 SetState(State::Remove);
	if (s == "update")	 SetState(State::Update);
	if (s == "hidden")	 SetState(State::Hidden);
}

void UIEntity::SetAction(Action a)
{
	action = a;
}

void UIEntity::SetAction(const std::string& a)
{
	if (a == "none")			SetAction(Action::None);
	if (a == "appclose")		SetAction(Action::AppClose);
	if (a == "apppause")		SetAction(Action::AppPause);
	if (a == "stateremove")		SetAction(Action::StateRemove);
	if (a == "statepause")		SetAction(Action::StatePause);
	if (a == "stateresume")		SetAction(Action::StateResume);
	if (a == "layerremove")		SetAction(Action::LayerRemove);
	if (a == "entityremove")	SetAction(Action::EntityRemove);
}

void UIEntity::SetMousePress(Action a)
{
	mousePress = a;
}

void UIEntity::SetMousePress(const std::string& a)
{
	if (a == "none")			SetMousePress(Action::None);
	if (a == "appclose")		SetMousePress(Action::AppClose);
	if (a == "apppause")		SetMousePress(Action::AppPause);
	if (a == "stateremove")		SetMousePress(Action::StateRemove);
	if (a == "statepause")		SetMousePress(Action::StatePause);
	if (a == "stateresume")		SetMousePress(Action::StateResume);
	if (a == "layerremove")		SetMousePress(Action::LayerRemove);
	if (a == "entityremove")	SetMousePress(Action::EntityRemove);
}