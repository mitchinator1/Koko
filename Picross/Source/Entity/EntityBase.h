#ifndef ENTITY_BASE_H
#define ENTITY_BASE_H
#include <vector>

namespace Entity
{
	class EntityBase
	{
	private:
		std::vector<float> m_Vertices;
		//Todo: Make vertices seperate class with vertices data, stride, and count.
		//include with mesh, can pass vertices class to mesh

	public:
		EntityBase(const std::vector<float>& vertices)
			: m_Vertices(ToScreenCoords(vertices))
		{
			
		}
		virtual ~EntityBase() {}

		void AddVertices(const std::vector<float>& vertices)
		{
			auto verticesToAdd = ToScreenCoords(vertices);
			for (auto& point : verticesToAdd)
			{
				m_Vertices.emplace_back(point);
			}

		}

		auto& GetVertices() { return m_Vertices; }

	protected:
		std::vector<float> ToScreenCoords(std::vector<float> vertices)
		{
			for (auto& point : vertices)
			{
				point = point / 50.0f - 1.0f;
			}

			return vertices;
		}
	};
}

#endif