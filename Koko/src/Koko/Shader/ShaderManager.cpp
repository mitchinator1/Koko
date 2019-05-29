#include "kkpch.h"
#include "ShaderManager.h"

namespace Koko
{
	ShaderManager::ShaderManager()
	{

	}

	ShaderManager::~ShaderManager()
	{

	}

	void ShaderManager::CreateShader(const std::string& name, const std::string& filepath)
	{
		if (m_Shaders.find(name) != m_Shaders.end())
		{
			return;
		}

		m_Shaders.emplace(name, std::make_unique<Shader::ShaderBase>(filepath));

		std::cout << "Shader '" << name << "' added from " << filepath << '\n';

	}

	ShaderManager* ShaderManager::GetShader(const std::string& name)
	{
		if (m_Shaders.find(name) != m_Shaders.end())
		{
			m_ActiveShader = name;
		}

		return this;
	}

	void ShaderManager::Bind()
	{
		if (m_ActiveShader == "")
		{
			return;
		}

		m_Shaders[m_ActiveShader]->Bind();
	}

	void ShaderManager::Unbind()
	{
		if (m_ActiveShader == "")
		{
			return;
		}

		m_Shaders[m_ActiveShader]->Unbind();
	}

}