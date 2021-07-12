#ifndef LAYER_H
#define LAYER_H
#include "Koko/Events/Event.h"
//#include "Koko/Mesh/Mesh.h"
//#include "Koko/Entity/Entity.h"
#include "Koko/Events/Action.h"

//#include "Koko/Text/TextManager.h"
#include "Koko/Entity/Flag.h"

namespace Koko
{
	class State;

	class Layer
	{
	protected:
		//Mesh* m_Mesh;
		//Mesh* m_TextMesh;

		//std::vector<Entity*> m_Entities;
		Flag m_Flag;

	public:
		//Entity::State updatestate = Entity::State::None;

	public:
		Layer() : /*m_Mesh(nullptr), m_TextMesh(nullptr)*/ { }
		virtual ~Layer()
		{
			//for (Entity* entity : m_Entities)
			{
				//delete entity;
			}
		}

		virtual void OnAttach() { /*CalculateMesh();*/ }
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e) {}

		//void PushEntity(Entity* entity) { m_Entities.emplace_back(entity); }
		/*void PopEntity(Entity* entity)
		{
			auto it = std::find(m_Entities.begin(), m_Entities.end(), entity);
			if (it != m_Entities.end())
			{
				m_Entities.erase(it);
				CalculateMesh();
			}
		}*/

		virtual void Notify(State* state) {}

		//void CalculateMesh()
		//{
		//	bool updateNeeded = false;

		//	for (auto& e : m_Entities)
		//	{
		//		if (e->state == Entity::State::Update)
		//		{
		//			updateNeeded = true;
		//			break;
		//		}
		//	}

		//	if (!updateNeeded)
		//	{
		//		return;
		//	}

		//	std::vector<float> vertices;

		//	for (auto& entity : m_Entities)
		//	{
		//		auto& v = entity->GetVertices();
		//		vertices.insert(vertices.end(), v.begin(), v.end());
		//	}

		//	if (!m_Mesh)
		//	{
		//		m_Mesh = new Mesh(vertices);
		//	}
		//	else
		//	{
		//		m_Mesh->UpdateVertices(vertices);
		//	}
		//	vertices.clear();

		//	for (auto& entity : m_Entities)
		//	{
		//		if (entity->GetText())
		//		{
		//			auto& v = entity->GetText()->GetVertices();
		//			vertices.insert(vertices.end(), v.begin(), v.end());
		//		}
		//	}

		//	if (!m_TextMesh)
		//	{
		//		std::vector<unsigned int> strides = { 3, 2, 3 };
		//		m_TextMesh = new Mesh(vertices, strides);
		//	}
		//	else
		//	{
		//		m_TextMesh->UpdateVertices(vertices);
		//	}
		//	m_TextMesh->SetTexture(TextManager::GetFont("Arial")->GetTexture()); // Temporary (Arial set to default)
		//}

		//inline auto& GetMesh() { return m_Mesh; }
		//inline auto& GetEntities() { return m_Entities; }
		//inline auto& GetTextMesh() { return m_TextMesh; }
		inline auto& GetState() { return m_Flag; }

	};

}

#endif