#ifndef FILE_PROGRAM_H
#define FILE_PROGRAM_H
#include <string>
#include <fstream>

class FileProgram
{
private:
	std::ifstream m_Stream;
	std::string m_CurrentLine;

public:
	FileProgram(const std::string& fileName);
	~FileProgram();

	bool GetLine();

private:
	void TrimLeadingSpace(std::string& value, const char* t = " \t\n\r\f\v");
	void IgnoreComment();

};

#endif