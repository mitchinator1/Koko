#ifndef STATE_BASE_H
#define STATE_BASE_H
#include <memory>
#include "Core.h"

#include "Renderer/Renderer.h"
#include "Utility/Stack.h"

#include "Event/Event.h"
#include "Event/Action.h"

#include "Layer/Layer.h"

class Application;

namespace Koko
{
	class KK_API State
	{
	public:
		bool remove = false;

	protected:
		//TODO: Add vector of actions
		std::unique_ptr<Renderer> m_Renderer;

		Stack<Layer> m_LayerStack;

	public:
		State() : m_Renderer(std::make_unique<Renderer>()) {}
		virtual ~State() {}

		virtual void Pause() {};
		virtual void Resume() {};

		virtual bool OnEvent(Event& e) = 0;
		virtual void OnUpdate(Event& e) = 0;
		virtual void Render() = 0;

		virtual void ChangeState(Application* app, State* state) = 0;

		virtual void Notify(Stack<State>* stack) = 0;
		virtual void NotifyLayers() = 0;
		virtual void ReceiveAction(Action action) = 0;
	};
}

#endif