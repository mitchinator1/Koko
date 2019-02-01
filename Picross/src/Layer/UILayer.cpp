#include "UILayer.h"

UILayer::UILayer()
{

}

UILayer::~UILayer()
{

}

void UILayer::OnAttach()
{
	CalculateMesh();
}

void UILayer::OnUpdate()
{
	CalculateMesh();
}

void UILayer::OnEvent(EventEngine::Event& e)
{
	using namespace EventEngine;
	Dispatcher dispatcher(e);
	dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(UILayer::OnMouseMovedEvent));
	dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(UILayer::OnMouseButtonPressedEvent));
}

void UILayer::PopEntity(Entity* entity)
{
	auto it = std::find(m_Entities.begin(), m_Entities.end(), entity);
	if (it != m_Entities.end())
	{
		m_Entities.erase(it);
		CalculateMesh();
	}
}

bool UILayer::OnMouseMovedEvent(EventEngine::MouseMovedEvent& e)
{
	bool hit = false;

	for (auto entity : m_Entities)
	{
		if (entity->OnMouseMovedEvent(e))
		{
			hit = true;
		}
	}

	return hit;
}

bool UILayer::OnMouseButtonPressedEvent(EventEngine::MouseButtonPressedEvent& e)
{
	//TODO: Pick left or right button
	for (auto entity : m_Entities)
	{
		if (entity->OnMouseButtonPressedEvent(e))
		{
			PopEntity(entity);
			return true;
		}
	}

	return false;
}