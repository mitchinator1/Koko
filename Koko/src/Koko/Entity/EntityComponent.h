#ifndef ENTITY_COMPONENT_H
#define ENTITY_COMPONENT_H
#include "Koko/Core.h"
#include "GLM/vec2.hpp"
#include "GLM/vec4.hpp"

namespace Koko
{
	struct KK_API Position
	{
		float x = 0.0f, y = 0.0f;
		Position() {}
		Position(const glm::vec2& v) : x(v.x), y(v.y) {}

		Position& operator+=(const Position& rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;
			return *this;
		}

		Position& operator-=(const Position& rhs)
		{
			this->x -= rhs.x;
			this->y -= rhs.y;
			return *this;
		}
	};

	struct KK_API Size
	{
		float width = 0.0f, height = 0.0f;
		Size() {}
		Size(const glm::vec2& v) : width(v.x), height(v.y) {}
	};

	struct KK_API Colour
	{
		float r = 0.0f, g = 0.0f, b = 0.0f, a = 0.0f;
		Colour() {}
		Colour(const glm::vec4& v) : r(v.r), g(v.g), b(v.b), a(v.a) {}
	};

}

#endif