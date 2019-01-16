#include "EntityBuilder.h"

Position EntityBuilder::GetPosition()
{
	Position pos;
	pos.x = 60.0f;
	pos.y = 70.0f;

	return pos;
}

Size EntityBuilder::GetSize()
{
	Size size;
	size.width = 20.0f;
	size.height = 20.0f;

	return size;
}

Colour EntityBuilder::GetColour()
{
	Colour colour;
	colour.r = 40.0f;
	colour.g = 60.0f;
	colour.b = 20.0f;
	colour.a = 100.0f;

	return colour;
}