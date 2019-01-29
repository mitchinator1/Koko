#include "EntityDirector.h"
#include "Utility/Node.h"

void EntityDirector::SetBuilder(Builder* builder)
{
	m_Builder = builder;
}

Entity* EntityDirector::GetEntity(Node& node)
{
	Entity* entity = new Entity();

	entity->position = node.GetVec2("position");
	entity->size	 = node.GetVec2("size");
	entity->colour	 = node.GetVec4("colour");

	return entity;
}