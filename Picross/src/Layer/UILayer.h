#ifndef UI_LAYER_H
#define UI_LAYER_H
#include "Layer.h"
#include "../Event/MouseEvent.h"

class UILayer : public Layer
{
public:
	UILayer();
	~UILayer();

	void OnAttach() override;
	void OnUpdate()	override;
	void OnEvent(EventEngine::Event& e) override;

	void PopEntity(Entity* entity) override;

private:
	bool OnMouseMovedEvent(EventEngine::MouseMovedEvent& e);
	bool OnMouseButtonPressedEvent(EventEngine::MouseButtonPressedEvent& e);

};

#endif