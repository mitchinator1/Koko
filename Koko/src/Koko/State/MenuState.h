#ifndef STATE_MENU_H
#define STATE_MENU_H
#include "State.h"

namespace Koko
{
	class KK_API MenuState : public State
	{
	public:
		MenuState();
		~MenuState();

		bool OnEvent(Event& e)		override;
		void OnUpdate(Event& e)		override;
		void Render()				override;

		void ChangeState(Application* app, State* state)	override;

		void Notify(Stack<State>* stack)		override;
		void NotifyLayers()						override;
		void ReceiveAction(Action action)		override;
	};
}

#endif