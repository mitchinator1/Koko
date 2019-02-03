#include "UIDropdown.h"
#include "Event/MouseEvent.h"

UIDropdown::~UIDropdown()
{
	for (auto& e : m_Entities)
	{
		delete e;
	}
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

void UIDropdown::AddEntity(Entity* entity)
{
	UpdateChildPosition(entity);

	m_Entities.emplace_back(entity);
	state = State::Update;
}

void UIDropdown::SetDirection(Direction d)
{
	this->direction = d;
}

void UIDropdown::SetDirection(const std::string& d)
{
	if (d == "up")		direction = Direction::Up;
	if (d == "right")	direction = Direction::Right;
	if (d == "down")	direction = Direction::Down;
	if (d == "left")	direction = Direction::Left;
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

void UIDropdown::UpdateChildPosition(Entity* entity)
{
	switch (direction)
	{
	case Direction::Up: {
		entity->position.x += position.x;
		entity->position.y = position.y - entity->position.y - entity->size.height;
	}
	break;
	case Direction::Right: {
		entity->position.y += position.y;
		entity->position.x = position.x + size.width;
	}
	break;
	case Direction::Down: {
		entity->position.x += position.x;
		entity->position.y = position.y + entity->position.y + size.height;
	}
	break;
	case Direction::Left: {
		entity->position.y += position.y;
		entity->position.x = position.x - entity->position.x - entity->size.width;
	}
	break;
	}
}