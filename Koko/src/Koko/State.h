#ifndef STATE_BASE_H
#define STATE_BASE_H
#include "Koko/Events/Event.h"

namespace Koko
{
	class State
	{
	protected:
		//protected:
			//TODO: Add vector of actions

			//Stack<Koko::Layer> m_LayerStack;

	public:
		virtual ~State() {}

		virtual void Pause() = 0;
		virtual void Resume() = 0;

		virtual bool OnEvent(Koko::Event& e) = 0;
		virtual void OnUpdate() = 0;
		virtual void Render() = 0;
		
		//virtual void Notify(Stack<State>* stack) = 0;
		//virtual void NotifyLayers() = 0;
		//virtual void ReceiveAction(Action action) = 0;
	};
}

#endif