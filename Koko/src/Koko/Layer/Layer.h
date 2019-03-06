#ifndef LAYER_H
#define LAYER_H
#include "Koko/Core.h"
#include "Koko/Event/Event.h"
#include "Koko/Mesh/Mesh.h"
#include "Koko/Entity/Entity.h"
#include "Koko/Event/Action.h"

namespace Koko
{
	class State;

	class Layer
	{
	protected:
		Mesh* m_Mesh;
		std::vector<Entity*> m_Entities;

	public:
		Entity::State updatestate = Entity::State::None;

	public:
		KK_API Layer() {}
		KK_API virtual ~Layer()
		{
			for (Entity* entity : m_Entities)
			{
				delete entity;
			}
		}

		KK_API virtual void OnAttach() { CalculateMesh(); }
		KK_API virtual void OnDetach() {}
		KK_API virtual void OnUpdate() {}
		KK_API virtual void OnEvent(Event& e) {}

		KK_API void PushEntity(Entity* entity) { m_Entities.emplace_back(entity); }
		KK_API void PopEntity(Entity* entity)
		{
			auto it = std::find(m_Entities.begin(), m_Entities.end(), entity);
			if (it != m_Entities.end())
			{
				m_Entities.erase(it);
				CalculateMesh();
			}
		}

		KK_API virtual void Notify(State* state) {}

		KK_API void CalculateMesh()
		{
			std::vector<float> vertices;

			for (auto entity : m_Entities)
			{
				auto v = entity->GetVertices();
				vertices.insert(vertices.end(), v.begin(), v.end());
			}

			m_Mesh = new Mesh(vertices);
		}

		KK_API inline auto& GetMesh() { return m_Mesh; }
		KK_API inline auto& GetEntities() { return m_Entities; }
	};

}

#endif