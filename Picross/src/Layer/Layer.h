#ifndef LAYER_H
#define LAYER_H
#include "../Event/Event.h"
#include "../Mesh/Mesh.h"
#include "../Entity/Entity.h"

class Layer
{
protected:
	Mesh* m_Mesh;
	std::vector<Entity*> m_Entities;

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
	virtual void OnEvent(EventEngine::Event& e) {}

	void PushEntity(Entity* entity) { m_Entities.emplace_back(entity); }
	virtual void PopEntity(Entity* entity) {}
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

	auto& GetMesh()		{ return m_Mesh; }
	auto& GetEntities() { return m_Entities; }
};

#endif