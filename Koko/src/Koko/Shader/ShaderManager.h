#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H
#include "Koko/Core/Core.h"
#include "ShaderBase.h"

namespace Koko
{
	class ShaderManager
	{
	private:
		static ShaderManager* s_Instance;
		static std::unordered_map<std::string, std::unique_ptr<ShaderBase>> s_Shaders;

	public:
		static bool CreateShader(const std::string& name, const std::string& filepath);
		static ShaderBase* GetShader(const std::string& name);

		static void DeleteShader(const std::string& name);
	};
}

#endif