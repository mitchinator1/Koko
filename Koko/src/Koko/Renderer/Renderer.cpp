#include "kkpch.h"
#include "Renderer.h"

#include "Koko/Mesh/Mesh.h"

#include "Koko/Utility/Stack.h"
#include "Koko/Layer/Layer.h"

#include "Koko/Shader/ShaderManager.h"

namespace Koko
{
	Renderer::Renderer()
		//: m_ShaderManager(std::make_unique<ShaderManager>())
		: m_ShaderManager(nullptr)
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

	void Renderer::Render(Stack<Layer>& stack)
	{
		Clear();

		Prepare();

		//TODO: Probably rendering backwards
		for (auto& layer : stack)
		{
			ShaderManager::GetShader("Basic")->Bind();
			RenderMesh(layer->GetMesh());

			ShaderManager::GetShader("Text")->Bind();
			//glEnable(GL_DEPTH_TEST);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			RenderMesh(layer->GetTextMesh());
		}

		CleanUp();
	}

	void Renderer::Render(Mesh* mesh)
	{
		mesh->Bind();
		glDrawElements(mesh->GetMode(), mesh->GetCount(), GL_UNSIGNED_INT, nullptr);
		mesh->Unbind();
	}

	void Renderer::Clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::Prepare() const
	{
		//m_ShaderManager->GetShader("Basic")->Bind();
	}

	void Renderer::CleanUp() const
	{
		//m_ShaderManager->Unbind();
	}
}