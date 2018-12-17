#include "Renderer.h"
#include "../Display.h"
#include "../Mesh/Mesh.h"
#include "../Shader/ShaderBase.h"

Renderer::Renderer(std::shared_ptr<Display> display)
	: m_Display(display), m_Shader(std::make_unique<Shader::ShaderBase>())
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH);
}


Renderer::~Renderer()
{
}

void Renderer::Render(Mesh* mesh) const
{
	Clear();

	Prepare();
	mesh->Bind();

	glDrawElements(mesh->GetMode(), mesh->GetCount(), GL_UNSIGNED_INT, nullptr);

	mesh->Unbind();

	CleanUp();
	Swap();
}

void Renderer::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Prepare() const
{
	m_Shader->Bind();
}

void Renderer::CleanUp() const
{
	m_Shader->Unbind();
}

void Renderer::Swap() const
{
	glfwSwapBuffers(m_Display->Window);
}