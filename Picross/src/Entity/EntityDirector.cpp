#include "EntityDirector.h"
#include "Utility/Node.h"

#include "UI/UIEntity.h"
#include "UI/UIDropdown.h"

//Temporary
#include <iostream>

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
	uiEntity->position  = node.GetVec2("position");
	uiEntity->size		= node.GetVec2("size");
	uiEntity->colour	= node.GetVec4("colour");

	return uiEntity;
}

Entity* EntityDirector::GetUIDropdown(Node& node)
{
	UIDropdown* dropdown = new UIDropdown();

	dropdown->position  = node.GetVec2("position");
	dropdown->size		= node.GetVec2("size");
	dropdown->colour	= node.GetVec4("colour");

	dropdown->SetDirection(node.GetValue("expand"));
	//TODO: Implement activation method

	for (auto& n : node.ChildNodes)
	{
		if (n.Name == "Entity")
		{
			UIEntity* entity = new UIEntity();

			entity->position	= n.GetVec2("position");
			entity->size		= n.GetVec2("size");
			entity->colour		= n.GetVec4("colour");

			entity->SetState(n.GetValue("state"));

			dropdown->AddEntity(entity);
		}
	}

	return dropdown;
}