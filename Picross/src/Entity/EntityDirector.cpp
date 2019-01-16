#include "EntityDirector.h"

void EntityDirector::SetBuilder(EntityBuilder* builder)
{
	m_Builder = builder;
}

Entity* EntityDirector::GetEntity()
{
	Entity* entity = new Entity();

	entity->position = m_Builder->GetPosition();
	entity->size	 = m_Builder->GetSize();
	entity->colour	 = m_Builder->GetColour();

	return entity;
}