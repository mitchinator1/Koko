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

void UILayer::OnEvent(EventEngine::Event& event)
{

}

void UILayer::PopEntity(Entity::EntityBase* entity)
{
	auto it = std::find(m_Entities.begin(), m_Entities.end(), entity);
	if (it != m_Entities.end())
	{
		m_Entities.erase(it);
	}
}