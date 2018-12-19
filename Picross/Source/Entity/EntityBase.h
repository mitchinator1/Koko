#ifndef ENTITY_BASE_H
#define ENTITY_BASE_H
#include <vector>

namespace Entity
{
	class EntityBase
	{
	public:
		float x, y, width, height;

	private:
		//std::vector<float> m_Vertices;
		//Todo: Make vertices seperate class with vertices data, stride, and count.
		//include with mesh, can pass vertices class to mesh

	public:
		EntityBase(float x, float y, float width, float height)
			: x(x), y(100.0f - y), width(width), height(height)
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
			std::vector<float> vertices;

			vertices.insert(vertices.end(), {
				x,			y,			0.0f,		80.0f, 40.0f, 50.0f, 100.0f,
				x,			y - height,	0.0f,		80.0f, 40.0f, 50.0f, 100.0f,
				x + width,	y - height,	0.0f,		80.0f, 40.0f, 50.0f, 100.0f,
				x + width,	y,			0.0f,		80.0f, 40.0f, 50.0f, 100.0f
				});

			return vertices;
		}
	};
}

#endif