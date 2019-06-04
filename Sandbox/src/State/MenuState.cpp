#include "MenuState.h"
#include "Koko/Input.h"

#include "Koko/Text.h"

#include "Koko/UI/DropdownElement.h"

MenuState::MenuState(const std::string& fileName)
	: Koko::State(fileName), m_Canvas(std::make_unique<Koko::Canvas>(0.0f, 0.0f, 100.0f, 100.0f))
{
	Koko::Dropdown* dropdown = new Koko::Dropdown();
	dropdown->X = 0.0f;
	dropdown->Y = 20.0f;
	dropdown->Z = 0.0f;
	dropdown->Width = 15.0f;
	dropdown->Height = 15.0f;
	dropdown->R = 90.0f;
	dropdown->G = 30.0f;
	dropdown->B = 18.0f;
	dropdown->A = 100.0f;

	m_Canvas->AddElement(dropdown);
}

MenuState::~MenuState()
{

}

bool MenuState::OnEvent(Koko::Event& e)
{
	if (Koko::Input::IsKeyPressed(KK_KEY_ESCAPE))
	{
		remove = true;
	}

	m_Canvas->OnEvent(e);

	for (int it = (int)m_LayerStack.size() - 1; it >= 0; --it)
	{
		m_LayerStack[it]->OnEvent(e);
		if (e.Handled)
		{
			m_State = Koko::Entity::State::Update;
			return true;
		}
	}

	NotifyLayers();

	m_State = Koko::Entity::State::None;
	return false;
}

void MenuState::OnUpdate()
{
	if (m_State == Koko::Entity::State::Update)
	{
		m_Canvas->OnUpdate();

		for (auto& layer : m_LayerStack)
		{
			layer->OnUpdate();
		}
		m_State = Koko::Entity::State::None;
	}
}

void MenuState::Render()
{
	m_Renderer->Render(m_LayerStack);
	m_Renderer->Render(m_Canvas->GetMesh());
}

void MenuState::Notify(Stack<State>* stack)
{
	//TODO: Change to action
	if (remove)
	{
		stack->Listen(Action::StateRemove);
		//stack->PopState();
	}
}

void MenuState::NotifyLayers()
{
	for (int i = 0; i < m_LayerStack.size(); ++i)
	{
		m_LayerStack[i]->Notify(this);
		if (m_LayerStack[i]->updatestate == Koko::Entity::State::Remove)
		{
			m_LayerStack.Pop(m_LayerStack[i]);
			--i;
		}
	}
}

void MenuState::ReceiveAction(Action action)
{
	if (action == Action::StateRemove)
	{
		remove = true;
	}

	if (action == Action::LayerRemove)
	{
		m_LayerStack.Pop();
	}
}