#include "Renderer.h"
#include "../Platform/Window.h"
#include "../Mesh/Mesh.h"
#include "../Shader/ShaderBase.h"

Renderer::Renderer()
	: m_Shader(std::make_unique<Shader::ShaderBase>())
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH);
}


Renderer::~Renderer()
{
}

void Renderer::RenderMesh(Mesh* mesh)
{
	if (!mesh)
	{
		return;
	}

	mesh->Bind();

	glDrawElements(mesh->GetMode(), mesh->GetCount(), GL_UNSIGNED_INT, nullptr);

	mesh->Unbind();
}

void Renderer::Render(LayerStack& layers)
{
	Clear();

	Prepare();

	for (int it = layers.front(); it <= layers.size(); ++it)
	{
		RenderMesh(layers[it]->GetMesh());
	}

	CleanUp();
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