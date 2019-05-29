#include "MenuState.h"
#include "Koko/Input.h"

#include "Koko/Text.h"
#include "Koko/Mesh/Texture.h"

MenuState::MenuState(const std::string& fileName)
	: Koko::State(fileName)
{
	//TODO: Load text from file, creating all needed TextData. Merge Text vertices to create text mesh. Text Mesh will need differing Z Values
	Koko::Text text({ "Arial", "Test string", 2.0f, { 30.0f, 40.0f, 0.0f }, { 1.0f, 1.0f, 0.8f, 1.0f } });
	auto font = std::make_shared<Koko::Font>(text.GetData().Font, 1800.0, 1400.0);
	text.CreateMesh(font);

	std::vector<unsigned int> strides = { 3, 2, 3 };
	m_TextMesh = new Mesh(text.GetVertices(), strides);

	m_TextMesh->SetTexture(font->GetTexture());
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

	for (int it = (int)m_LayerStack.size() - 1; it >= 0; --it)
	{
		m_LayerStack[it]->OnEvent(e);
		if (e.Handled)
		{
			return true;
		}
	}

	NotifyLayers();

	return false;
}

void MenuState::OnUpdate(Koko::Event& e)
{

}

void MenuState::Render()
{
	m_ShaderManager->GetShader("Basic")->Bind();
	m_Renderer->Render(m_LayerStack);
	m_ShaderManager->Unbind();

	if (m_TextMesh)
	{
		m_ShaderManager->GetShader("Text")->Bind();
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		m_Renderer->Render(m_TextMesh);
		m_ShaderManager->Unbind();
	}
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