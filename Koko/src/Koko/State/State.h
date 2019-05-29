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

#include "Koko/Shader/ShaderManager.h"

namespace Koko
{
	class Application;

	class KK_API State
	{
	public:
		bool remove = false;

	protected:
		//TODO: Add vector of actions
		std::unique_ptr<Renderer> m_Renderer;

		Stack<Layer> m_LayerStack;

	public:
		State(const std::string& fileName) : m_Renderer(std::make_unique<Renderer>())
		{
			LayerBuilder builder(fileName);
			builder.Build(m_LayerStack);

			for (auto& layer : m_LayerStack)
			{
				ShaderManager::CreateShader(layer->GetShaderName(), layer->GetShaderPath());
			}

			ShaderManager::CreateShader("Text", "Resources/Shader/Text.Shader");
		}
		virtual ~State() {}

		virtual void Pause() {};
		virtual void Resume() {};

		virtual bool OnEvent(Event& e)	= 0;
		virtual void OnUpdate(Event& e) = 0;
		virtual void Render()			= 0;

		//virtual void ChangeState(Application* app, State* state) {};

		virtual void Notify(Stack<State>* stack)	= 0;
		virtual void NotifyLayers()					= 0;
		virtual void ReceiveAction(Action action)	= 0;
	};
}

#endif