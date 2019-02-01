#include "EntityDirector.h"
#include "Utility/Node.h"

#include "UI/UIEntity.h"

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

Entity* EntityDirector::GetUIEntity(Node& node)
{
	UIEntity* uiEntity = new UIEntity();

	//TODO: add traits
	uiEntity->position = node.GetVec2("position");
	uiEntity->size = node.GetVec2("size");
	uiEntity->colour = node.GetVec4("colour");

	return uiEntity;
}

Entity* EntityDirector::GetUIDropdown(Node& node)
{
	UIEntity* dropdown = new UIEntity();

	//TODO: add traits
	dropdown->position = node.GetVec2("position");
	dropdown->size = node.GetVec2("size");
	dropdown->colour = node.GetVec4("colour");

	return dropdown;
}