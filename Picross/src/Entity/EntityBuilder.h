#ifndef ENTITY_BUILDER_H
#define ENTITY_BUILDER_H
#include "../Utility/Builder.h"
#include "Entity.h"
#include "EntityComponent.h"

class EntityBuilder : public Builder
{
public:
	Position GetPosition();
	Size GetSize();
	Colour GetColour();
};

#endif