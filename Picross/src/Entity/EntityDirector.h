#ifndef ENTITY_DIRECTOR_H
#define ENTITY_DIRECTOR_H
#include "EntityBuilder.h"

class EntityDirector
{
private:
	EntityBuilder* m_Builder;

public:
	void SetBuilder(EntityBuilder* builder);

	Entity* GetEntity();

};

#endif