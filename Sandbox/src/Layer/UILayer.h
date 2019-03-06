#ifndef UI_LAYER_H
#define UI_LAYER_H
#include "Koko/Layer/Layer.h"
#include "Koko/Event/MouseEvent.h"
#include "Koko/Event/Action.h"

class UILayer : public Koko::Layer
{
private:
	std::vector<Action> m_Actions;
	Koko::Entity::State m_State = Koko::Entity::State::None;

public:
	UILayer();
	~UILayer();

	void OnAttach() override;
	void OnUpdate()	override;
	void OnEvent(Koko::Event& e) override;

	void Notify(Koko::State* state) override;

private:
	bool OnMouseMovedEvent(Koko::MouseMovedEvent& e);
	bool OnMouseButtonPressedEvent(Koko::MouseButtonPressedEvent& e);

};

#endif