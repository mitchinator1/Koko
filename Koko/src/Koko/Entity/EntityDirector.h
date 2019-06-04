#ifndef ENTITY_DIRECTOR_H
#define ENTITY_DIRECTOR_H
#include "Koko/Utility/Builder.h"
#include "Entity.h"

namespace Koko
{
	struct Node;
	struct TextData;
	class UIDropdown;

	class EntityDirector
	{
	private:
		Builder* m_Builder;

	public:
		void SetBuilder(Builder* builder);

		Entity* GetEntity(Node& node);
		Entity* GetUIEntity(Node& node);
		Entity* GetUIDropdown(Node& node);

	private:
		TextData GetTextData(Node& node);
		void AddDropdownChildren(UIDropdown* dropdown, Node& node);
	};

}

#endif