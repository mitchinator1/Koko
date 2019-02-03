#include "UIDropdown.h"
#include "Event/MouseEvent.h"

//Temporary
#include <iostream>

UIDropdown::~UIDropdown()
{
	for (auto& e : m_Entities)
	{
		delete e;
	}
}

std::vector<float> UIDropdown::GetVertices()
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

bool UIDropdown::OnMouseMovedEvent(EventEngine::MouseMovedEvent& e)
{
	bool hit = false;

	if (InHitbox(e.GetX(), e.GetY()))
	{
		if (!Reveal())
		{
			state = State::Update;
		}
		else
		{
			state = State::Selected;
		}
		hit = true;
	}
	else if (state == State::Selected)
	{
		state = State::None;
	}

	for (auto& entity : m_Entities)
	{
		if (entity->InHitbox(e.GetX(), e.GetY()))
		{
			entity->state = State::Selected;
			hit = true;
		}
		else if (entity->state == State::Selected)
		{
			entity->state = State::None;
		}
	}

	if (!hit)
	{
		if (!Hide())
		{
			state = State::Update;
		}
	}
	
	return hit;
}

bool UIDropdown::OnMouseButtonPressedEvent(EventEngine::MouseButtonPressedEvent& e)
{
	for (auto& entity : m_Entities)
	{
		entity->OnMouseButtonPressedEvent(e);
		if (entity->state == State::Remove)
		{
			PopEntity(entity);
			state = State::Update;
			Hide();
			return true;
		}
	}

	if (state == State::Selected)
	{
		state = State::Remove;
		return true;
	}

	return false;
}

bool UIDropdown::Reveal()
{
	bool revealed = true;

	for (auto& entity : m_Entities)
	{
		if (entity->state == State::Hidden)
		{
			entity->state = State::None;
			revealed = false;
		}
	}
	return revealed;
}

bool UIDropdown::Hide()
{
	bool hidden = true;

	for (auto& entity : m_Entities)
	{
		if (entity->state != State::Hidden)
		{
			entity->state = State::Hidden;
			hidden = false;
		}
	}
	return hidden;
}