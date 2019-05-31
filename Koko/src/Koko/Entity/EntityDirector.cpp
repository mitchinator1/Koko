#include "kkpch.h"
#include "EntityDirector.h"
#include "Koko/Utility/Node.h"

#include "Koko/UI/UIEntity.h"
#include "Koko/UI/UIDropdown.h"

#include "Koko/Text.h"

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
				dropdown->SetGroupingDirection(n.GetValue("grouping"));

				for (auto& child : n.ChildNodes)
				{ 
					if (child.Name == "Entity")
					{
						dropdown->AddEntity(GetUIEntity(child));
					}
				}
			}

			if (n.Name == "Text")
			{
				TextData data;
				data.Font = n.GetValue("font");
				if (n.GetValue("centered") == "true")
				{
					data.Centered = true;
				}

				std::string::size_type sz;
				data.Size = std::stof(n.GetValue("size"), &sz);
				data.ID = std::stoi(n.GetValue("id"), &sz);

				data.X = dropdown->position.x;
				data.Y = dropdown->position.y + (data.Size * 2.0f);
				data.Z = dropdown->position.z;

				dropdown->SetText(new Text(data));

			}
		}

		return dropdown;
	}

}