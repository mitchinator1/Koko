#ifndef ENTITY_DIRECTOR_H
#define ENTITY_DIRECTOR_H
#include "Utility/Builder.h"
#include "Entity.h"

struct Node;

class EntityDirector
{
private:
	Builder* m_Builder;

public:
	void SetBuilder(Builder* builder);

	Entity* GetEntity(Node& node);

};

#endif