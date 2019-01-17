#ifndef ENTITY_COMPONENT_H
#define ENTITY_COMPONENT_H
#include "GLM/vec2.hpp"
#include "GLM/vec4.hpp"

struct Position
{
	float x, y;
	Position() {}
	Position(const glm::vec2& v) : x(v.x), y(v.y) {}
};

struct Size
{
	float width, height;
	Size() {}
	Size(const glm::vec2& v) : width(v.x), height(v.y) {}
};

struct Colour
{
	float r, g, b, a;
	Colour() {}
	Colour(const glm::vec4& v) : r(v.r), g(v.g), b(v.b), a(v.a) {}
};

#endif