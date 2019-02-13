#ifndef UI_LAYER_H
#define UI_LAYER_H
#include "Layer.h"
#include "Event/MouseEvent.h"
#include "Event/Action.h"

class UILayer : public Layer
{
private:
	std::vector<Action> m_Actions;
	Entity::State m_State = Entity::State::None;

public:
	UILayer();
	~UILayer();

	void OnAttach() override;
	void OnUpdate()	override;
	void OnEvent(EventEngine::Event& e) override;

	void Notify(State* state) override;

private:
	bool OnMouseMovedEvent(EventEngine::MouseMovedEvent& e);
	bool OnMouseButtonPressedEvent(EventEngine::MouseButtonPressedEvent& e);

};

#endif