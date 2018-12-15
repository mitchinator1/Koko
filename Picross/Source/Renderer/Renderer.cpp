#include "Renderer.h"
#include "../Display.h"
#include "../Mesh/Mesh.h"
#include "../Shader/ShaderBase.h"

Renderer::Renderer(std::shared_ptr<Display> display)
	: m_Display(display)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


Renderer::~Renderer()
{
}

void Renderer::Render(Mesh* mesh) const
{
	Clear();

	mesh->Bind();

	mesh->Unbind();

	Swap();
}

void Renderer::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Prepare()
{
	m_Shader->Bind();
}

void Renderer::CleanUp()
{
	m_Shader->Unbind();
}

void Renderer::Swap() const
{
	glfwSwapBuffers(m_Display->Window);
}