#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H
#include "kkpch.h"
#include "Koko/Core.h"
#include "GLM/glm.hpp"

namespace Koko
{
	struct ShaderProgramSource
	{
		std::string vertexSource;
		std::string fragmentSource;
	};

	class ShaderProgram
	{
	private:
		std::unordered_map<std::string, int> m_UniformLocationCache;

	protected:
		int m_RendererID;

	public:
		KK_API ShaderProgram(const std::string& filepath = "Resources/Shader/Basic.shader") noexcept;
		KK_API virtual ~ShaderProgram();

		KK_API void Bind() const;
		KK_API void Unbind() const;

		KK_API bool IsValid() const;

	private:
		ShaderProgramSource ParseShader(const std::string& filepath);
		unsigned int CompileShader(unsigned int type, const std::string& source);
		unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

	};
}

#endif