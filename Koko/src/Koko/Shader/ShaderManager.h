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
		static ShaderManager* s_Instance;
		static std::unordered_map<std::string, std::unique_ptr<ShaderBase>> s_Shaders;

	public:
		KK_API static bool CreateShader(const std::string& name, const std::string& filepath);
		KK_API static ShaderBase* GetShader(const std::string& name);

		KK_API static void DeleteShader(const std::string& name);
	};
}

#endif