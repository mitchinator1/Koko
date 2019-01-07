#ifndef UI_LAYER_H
#define UI_LAYER_H
#include "Layer.h"

class UILayer : public Layer
{
public:
	UILayer();
	~UILayer();

	void OnAttach() override;
	void OnUpdate()	override;
	void OnEvent(EventEngine::Event& event) override;

	void PopEntity(Entity::EntityBase* entity) override;

};

#endif