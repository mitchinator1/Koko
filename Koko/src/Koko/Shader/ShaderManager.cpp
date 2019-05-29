#include "kkpch.h"
#include "ShaderManager.h"

namespace Koko
{
	ShaderManager* ShaderManager::s_Instance = new ShaderManager();
	std::unordered_map<std::string, std::unique_ptr<ShaderBase>> ShaderManager::s_Shaders = {};

	bool ShaderManager::CreateShader(const std::string& name, const std::string& filepath)
	{
		if (s_Shaders.find(name) != s_Shaders.end())
		{
			return true;
		}

		s_Shaders.emplace(name, std::make_unique<ShaderBase>(filepath));

		if (!s_Shaders[name]->IsValid())
		{
			std::cout << "Shader '" << name << "' at '" << filepath << "' not valid.\n";
			s_Shaders.erase(name);
			return false;
		}

		return true;
	}

	ShaderBase* ShaderManager::GetShader(const std::string& name)
	{
		if (s_Shaders.find(name) != s_Shaders.end())
		{
			return s_Shaders[name].get();
		}

		return s_Shaders["Basic"].get();
	}

	void ShaderManager::DeleteShader(const std::string& name)
	{
		if (s_Shaders.find(name) != s_Shaders.end())
		{
			s_Shaders.erase(name);
		}
	}

}