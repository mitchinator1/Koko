#include "EntityBuilder.h"

Position EntityBuilder::GetPosition()
{
	std::string position = GetPair();

	while (!FindTrait("<Entity"))
	{
		position = GetPair();
	}
	
	return GetVec2("position");
}

Size EntityBuilder::GetSize()
{
	return GetVec2("size");
}

Colour EntityBuilder::GetColour()
{
	return GetVec4("colour");
}