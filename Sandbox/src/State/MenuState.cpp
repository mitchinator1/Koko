#include "MenuState.h"
#include "Koko/Input.h"

#include "Koko/Renderer/Renderer.h"

#include "Koko/Application.h"
#include "Koko/UI/Canvas.h"

//#include "Koko/Shader/ShaderManager.h"
#include "Koko/Layer/LayerBuilder.h"

MenuState::MenuState(const std::string& fileName)
	: m_Renderer(std::make_unique<Koko::Renderer>())
	, m_Canvas(std::make_unique<Koko::Canvas>())
{
	Koko::LayerBuilder builder(fileName);
	builder.Build(m_Canvas.get());

	//Koko::ShaderManager::CreateShader("Text", "Resources/Shader/Text.Shader");
	//Koko::ShaderManager::CreateShader("Basic", "Resources/Shader/Basic.Shader");
}

MenuState::~MenuState()
{

}

bool MenuState::OnEvent(Koko::Event& e)
{
	if (Koko::Input::IsKeyPressed(KK_KEY_ESCAPE))
	{
		Koko::Application::Get().Quit();
	}

	m_Canvas->OnEvent(e);
	if (m_Canvas->GetState().Check(KK_UPDATENEEDED))
	{
		m_Flag.Enable(KK_UPDATENEEDED);
		return true;
	}
	
	//NotifyLayers();

	m_Flag.Disable(KK_UPDATENEEDED);
	return false;
}

void MenuState::OnUpdate()
{
	if (m_Flag.Check(KK_UPDATENEEDED))
	{
		m_Canvas->OnUpdate();

		m_Flag.Disable(KK_UPDATENEEDED);
	}
}

void MenuState::Render()
{
	//m_Renderer->Render(m_LayerStack);
	m_Renderer->Render(m_Canvas->GetMesh());
}

//void MenuState::Notify(Stack<State>* stack)
//{
//	//TODO: Change to action
//	if (remove)
//	{
//		stack->Listen(Action::StateRemove);
//		//stack->PopState();
//	}
//}
//
//void MenuState::NotifyLayers()
//{
//	for (int i = 0; i < m_LayerStack.size(); ++i)
//	{
//		m_LayerStack[i]->Notify(this);
//		if (m_LayerStack[i]->updatestate == Koko::Entity::State::Remove)
//		{
//			m_LayerStack.Pop(m_LayerStack[i]);
//			--i;
//		}
//	}
//}
//
//void MenuState::ReceiveAction(Action action)
//{
//	if (action == Action::StateRemove)
//	{
//		remove = true;
//	}
//
//	if (action == Action::LayerRemove)
//	{
//		m_LayerStack.Pop();
//	}
//}