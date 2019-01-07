#ifndef ENTITY_BASE_H
#define ENTITY_BASE_H
#include <vector>

namespace Entity
{
	class EntityBase
	{
	public:
		float x, y, width, height;
		float r, g, b;

		bool mouseOver = false;

	private:
		//std::vector<float> m_Vertices;
		//Todo: Make vertices seperate class with vertices data, stride, and count.
		//include with mesh, can pass vertices class to mesh

	public:
		EntityBase(float x, float y, float width, float height, float r = 100.0f, float g = 100.0f, float b = 100.0f)
			: x(x), y(y), width(width), height(height)
			, r(r), g(g), b(b)
		{
			
		}
		virtual ~EntityBase() {}

		std::vector<float> GetVertices()
		{ 
			auto vertices = CalculateVertices();

			return ToViewportSpace(vertices);
		}

	protected:
		std::vector<float> ToViewportSpace(std::vector<float> vertices)
		{
			for (auto& point : vertices)
			{
				point = point / 50.0f - 1.0f;
			}

			return vertices;
		}

		std::vector<float> CalculateVertices()
		{
			float flipY = 100.0f - y;

			std::vector<float> vertices;

			vertices.insert(vertices.end(), {
				x,			flipY,			0.0f,		r, g, b, 100.0f,
				x,			flipY - height,	0.0f,		r, g, b, 100.0f,
				x + width,	flipY - height,	0.0f,		r, g, b, 100.0f,
				x + width,	flipY,			0.0f,		r, g, b, 100.0f
				});

			return vertices;
		}
	};
}

#endif