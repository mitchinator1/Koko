#ifndef FILE_PROGRAM_H
#define FILE_PROGRAM_H
#include <string>
#include <fstream>
#include "GLM/vec2.hpp"
#include "GLM/vec4.hpp"

class FileProgram
{
private:
	std::ifstream m_Stream;
	std::string m_CurrentLine;

public:
	FileProgram(const std::string& filePath);
	~FileProgram();

	bool LoadLine();
	bool FindTrait(const std::string& target);
	inline std::string GetLine() { return m_CurrentLine; }

	glm::vec2 GetVec2(const std::string& v);
	glm::vec4 GetVec4(const std::string& v);

private:
	void TrimLeadingSpace(std::string& value, const char* t = " \t\n\r\f\v");
	void IgnoreComment();

};

#endif