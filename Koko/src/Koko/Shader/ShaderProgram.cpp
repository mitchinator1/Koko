#include "kkpch.h"
#include "ShaderProgram.h"

#include "glad/glad.h"
#include "GLM/gtc/type_ptr.hpp"

namespace Koko
{
	ShaderProgram::ShaderProgram(const std::string& filepath) noexcept
		:m_RendererID(0)
	{
		ShaderProgramSource source = ParseShader(filepath);
		m_RendererID = CreateShader(source.vertexSource, source.fragmentSource);
	}

	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(m_RendererID);
	}

	void ShaderProgram::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void ShaderProgram::Unbind() const
	{
		glUseProgram(0);
	}

	bool ShaderProgram::IsValid() const
	{
		if (m_RendererID == 0)
		{
			return false;
		}
		return true;
	}

	ShaderProgramSource ShaderProgram::ParseShader(const std::string& filepath)
	{
		std::ifstream stream(filepath);

		enum class ShaderType
		{
			NONE = -1, VERTEX = 0, FRAGMENT = 1
		};

		std::string line;
		std::stringstream ss[2];
		ShaderType type = ShaderType::NONE;
		while (getline(stream, line))
		{
			if (line.find("#shader") != std::string::npos)
			{
				if (line.find("vertex") != std::string::npos)
					type = ShaderType::VERTEX;
				else if (line.find("fragment") != std::string::npos)
					type = ShaderType::FRAGMENT;
			}
			else
			{
				ss[(unsigned int)type] << line << '\n';
			}
		}

		return { ss[0].str(), ss[1].str() };

	}

	unsigned int ShaderProgram::CompileShader(unsigned int type, const std::string& source)
	{
		unsigned int id = glCreateShader(type);

		if (source.empty())
		{
			glDeleteShader(id);
			id = 0;
			return id;
		}

		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)_malloca(length * sizeof(char)); // Changed from alloca to _malloca
			glGetShaderInfoLog(id, length, &length, message);
			std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader.\n";
			std::cout << message << '\n';
			glDeleteShader(id);
			return 0;
		}

		return id;
	}

	unsigned int ShaderProgram::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
	{
		unsigned int program = glCreateProgram();
		unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
		unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

		if (vs == 0 || fs == 0)
		{
			glDeleteShader(vs);
			glDeleteShader(fs);
			glDeleteProgram(program);
			program = 0;
			return program;
		}

		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vs);
		glDeleteShader(fs);

		return program;
	}

}