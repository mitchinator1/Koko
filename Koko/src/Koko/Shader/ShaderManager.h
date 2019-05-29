#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H
#include "kkpch.h"
#include "Koko/Core.h"

#include "ShaderBase.h"

namespace Koko
{
	class ShaderManager
	{
	private:
		std::unordered_map<std::string, std::unique_ptr<Shader::ShaderBase>> m_Shaders;

		std::string m_ActiveShader = "";

	public:
		KK_API ShaderManager();
		KK_API ~ShaderManager();

		KK_API void CreateShader(const std::string& name, const std::string& filepath);

		KK_API ShaderManager* GetShader(const std::string& name);
		KK_API void Bind();
		KK_API void Unbind();

	};
}

#endif