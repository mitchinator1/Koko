#ifndef UI_LAYER_H
#define UI_LAYER_H
#include "Layer.h"
#include "Koko/Events/Action.h"
#include "Koko/Entity/Entity.h"

namespace Koko
{
	class MouseMovedEvent;
	class MouseButtonPressedEvent;

	class UILayer : public Layer
	{
	private:
		std::vector<Action> m_Actions;
		Entity::State m_State = Entity::State::None;

	public:
		~UILayer() override {};

		void OnAttach() override;
		void OnUpdate();
		void OnEvent(Event& e) override;

		//void Notify(Entity::State* state) override;

	private:
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);

	};
}

#endif