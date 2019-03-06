#ifndef STATE_BASE_H
#define STATE_BASE_H
#include "kkpch.h"
#include "Koko/Core.h"

#include "Koko/Renderer/Renderer.h"
#include "Koko/Utility/Stack.h"

#include "Koko/Event/Event.h"
#include "Koko/Event/Action.h"

#include "Koko/Layer/Layer.h"

#include "Koko/Layer/LayerBuilder.h"

namespace Koko
{
	class Application;

	class State
	{
	public:
		bool remove = false;

	protected:
		//TODO: Add vector of actions
		std::unique_ptr<Renderer> m_Renderer;

		Stack<Layer> m_LayerStack;

	public:
		KK_API State(const std::string& fileName) : m_Renderer(std::make_unique<Renderer>())
		{
			LayerBuilder builder(fileName);
			builder.Build(m_LayerStack);
		}
		KK_API virtual ~State() {}

		KK_API virtual void Pause() {};
		KK_API virtual void Resume() {};

		KK_API virtual bool OnEvent(Event& e) = 0;
		KK_API virtual void OnUpdate(Event& e) = 0;
		KK_API virtual void Render() = 0;

		//virtual void ChangeState(Application* app, State* state) {};

		KK_API virtual void Notify(Stack<State>* stack) = 0;
		KK_API virtual void NotifyLayers() = 0;
		KK_API virtual void ReceiveAction(Action action) = 0;
	};
}

#endif