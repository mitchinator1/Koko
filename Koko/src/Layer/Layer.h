#ifndef LAYER_H
#define LAYER_H
#include "Core.h"
#include "Event/Event.h"
#include "Mesh/Mesh.h"
#include "Entity/Entity.h"
#include "Event/Action.h"

namespace Koko
{
	class State;

	class KK_API Layer
	{
	protected:
		Mesh* m_Mesh;
		std::vector<Entity*> m_Entities;

	public:
		Entity::State updatestate = Entity::State::None;

	public:
		Layer() {}
		virtual ~Layer()
		{
			for (Entity* entity : m_Entities)
			{
				delete entity;
			}
		}

		virtual void OnAttach() { CalculateMesh(); }
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e) {}

		void PushEntity(Entity* entity) { m_Entities.emplace_back(entity); }
		void PopEntity(Entity* entity)
		{
			auto it = std::find(m_Entities.begin(), m_Entities.end(), entity);
			if (it != m_Entities.end())
			{
				m_Entities.erase(it);
				CalculateMesh();
			}
		}

		virtual void Notify(State* state) {}

		void CalculateMesh()
		{
			std::vector<float> vertices;

			for (auto entity : m_Entities)
			{
				auto v = entity->GetVertices();
				vertices.insert(vertices.end(), v.begin(), v.end());
			}

			m_Mesh = new Mesh(vertices);
		}

		inline auto& GetMesh() { return m_Mesh; }
		inline auto& GetEntities() { return m_Entities; }
	};

}

#endif