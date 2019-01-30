#ifndef FILE_PROGRAM_H
#define FILE_PROGRAM_H
#include <string>
#include <fstream>

class FileProgram
{
private:
	std::string m_FilePath;

	std::ifstream m_Stream;
	std::string m_CurrentLine;

	std::string m_Contents;

	size_t m_Start = 0;
	size_t m_End;

public:
	FileProgram(const std::string& filePath);
	~FileProgram();

	bool GetLine();

	bool Open();
	void Load(const std::string& start = "", const std::string& end = "");
	void Close();

	void SetStart(const std::string& start, size_t offset = 0);
	void SetStart(size_t start);
	void SetEnd(const std::string& end, size_t offset = 0);
	std::string GetSetString();

	inline bool Empty() { return m_Contents.empty(); }

private:
	void TrimLeadingSpace(std::string& value, const char* t = " \t\n\r\f\v");
	void IgnoreComment();

};

#endif