#include "kkpch.h"
#include "EntityDirector.h"
#include "Koko/Utility/Node.h"

#include "Koko/UI/UIEntity.h"
#include "Koko/UI/UIDropdown.h"

#include "Koko/Text.h"
#include "Koko/Text/TextManager.h"

namespace Koko
{
	void EntityDirector::SetBuilder(Builder* builder)
	{
		m_Builder = builder;
	}

	Entity* EntityDirector::GetEntity(Node& node)
	{
		Entity* entity = new Entity();

		entity->position = node.GetVec2("position");
		entity->size = node.GetVec2("size");
		entity->colour = node.GetVec4("colour");

		return entity;
	}

	Entity* EntityDirector::GetUIEntity(Node& node)
	{
		UIEntity* uiEntity = new UIEntity();

		uiEntity->position = node.GetVec2("position");
		uiEntity->size = node.GetVec2("size");
		uiEntity->colour = node.GetVec4("colour");

		uiEntity->SetState(node.GetValue("state"));
		uiEntity->SetAction(node.GetValue("action"));

		for (auto& child : node.ChildNodes)
		{
			if (child.Name == "MousePress")
			{
				uiEntity->SetMousePress(child.InnerText);
			}
			if (child.Name == "Text")
			{
				uiEntity->SetText(new Text(GetTextData(child)));
			}
		}

		return uiEntity;
	}

	Entity* EntityDirector::GetUIDropdown(Node& node)
	{
		UIDropdown* dropdown = new UIDropdown();

		dropdown->position = node.GetVec2("position");
		dropdown->size = node.GetVec2("size");
		dropdown->colour = node.GetVec4("colour");

		dropdown->SetDirection(node.GetValue("expand"));
		//TODO: Implement activation method

		for (auto& n : node.ChildNodes)
		{
			if (n.Name == "Children")
			{
				AddDropdownChildren(dropdown, n);
			}

			if (n.Name == "Text")
			{
				dropdown->SetText(new Text(GetTextData(n)));
			}
		}

		return dropdown;
	}

	TextData EntityDirector::GetTextData(Node& node)
	{
		TextData data;

		data.Font = node.GetValue("font");
		if (node.GetValue("centered") == "true")
		{
			data.Centered = true;
		}

		std::string::size_type sz;
		data.Size = std::stof(node.GetValue("size"), &sz);
		data.ID = std::stoi(node.GetValue("id"), &sz);

		TextManager::AddFont(data.Font);

		return data;
	}

	void EntityDirector::AddDropdownChildren(UIDropdown* dropdown, Node& node)
	{
		dropdown->SetGroupingDirection(node.GetValue("grouping"));

		for (auto& n : node.ChildNodes)
		{
			if (n.Name == "Entity")
			{
				dropdown->AddEntity(GetUIEntity(n));
			}
		}
	}

}