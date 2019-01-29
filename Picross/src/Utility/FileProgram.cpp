#include "FileProgram.h"
#include <iostream>

FileProgram::FileProgram(const std::string& filepath)
	: m_FilePath(filepath)
{

}

FileProgram::~FileProgram()
{
	if (m_Stream.is_open())
	{
		m_Stream.close();
	}
}

bool FileProgram::GetLine()
{
	std::getline(m_Stream, m_CurrentLine);

	if (m_CurrentLine.size() == 0)
	{
		return false;
	}

	TrimLeadingSpace(m_CurrentLine);
	IgnoreComment();

	if (!m_Stream.good())
	{
		return false;
	}

	return true;
}

bool FileProgram::Open()
{
	m_Stream.open(m_FilePath);

	if (!m_Stream)
	{
		std::cout << "Failed to open file at " << m_FilePath << '\n';
		return false;
	}

	return true;
}

void FileProgram::Load(const std::string& start, const std::string& end)
{
	if (!Open())
	{
		return;
	}

	bool begin = false;

	if (start.size() > 0 && end.size() > 0)
	{
		while (std::getline(m_Stream, m_CurrentLine))
		{
			if (m_CurrentLine.find(end) != std::string::npos && begin)
			{
				break;
			}
			if (m_CurrentLine.find(start) != std::string::npos)
			{
				begin = true;
			}
			if (begin)
			{
				IgnoreComment();
				TrimLeadingSpace(m_CurrentLine);
				m_Contents += m_CurrentLine;
			}
		}
	}
	else
	{
		while (std::getline(m_Stream, m_CurrentLine))
		{
			IgnoreComment();
			TrimLeadingSpace(m_CurrentLine);
			m_Contents += m_CurrentLine;
		}
	}
}

void FileProgram::Close()
{
	m_Stream.close();
}

void FileProgram::SetStart(const std::string& start, size_t offset)
{
	m_Start = m_Contents.find_first_of(start) + offset;
}

void FileProgram::SetStart(size_t start)
{
	m_Start = start;
}

void FileProgram::SetEnd(const std::string& end, size_t offset)
{
	m_End = m_Contents.find_first_of(end) + offset;
}

std::string FileProgram::GetSetString()
{
	std::string value = m_Contents.substr(m_Start, m_End - m_Start);

	m_Contents.erase(m_Start, m_End);

	return value;
}

void FileProgram::TrimLeadingSpace(std::string& value, const char* t)
{
	value.erase(0, value.find_first_not_of(t));
}

void FileProgram::IgnoreComment()
{
	if (m_CurrentLine.find("<!--") != std::string::npos)
	{
		if (m_CurrentLine.find("-->") != std::string::npos)
		{
			std::getline(m_Stream, m_CurrentLine);
			TrimLeadingSpace(m_CurrentLine);
			return;
		}
		while (std::getline(m_Stream, m_CurrentLine))
		{
			if (m_CurrentLine.find("-->") != std::string::npos)
			{
				std::getline(m_Stream, m_CurrentLine);
				TrimLeadingSpace(m_CurrentLine);
				IgnoreComment();
				break;
			}
		}
	}
}