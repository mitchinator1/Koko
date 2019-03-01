#ifndef GAME_LAYER_H
#define GAME_LAYER_H
#include "Layer/Layer.h"

class GameLayer : public Koko::Layer
{
private:
	std::vector<Action> m_Actions;
	Koko::Entity::State m_State = Koko::Entity::State::None;

public:
	GameLayer();
	~GameLayer();

	void OnAttach() override;
	void OnUpdate()	override;
	void OnEvent(Koko::Event& e) override;

	void Notify(Koko::State* state) override;

private:
	bool OnMouseMovedEvent(Koko::MouseMovedEvent& e);
	bool OnMouseButtonPressedEvent(Koko::MouseButtonPressedEvent& e);
};

#endif