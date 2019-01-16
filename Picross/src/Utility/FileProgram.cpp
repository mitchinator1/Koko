#include "FileProgram.h"
#include <iostream>

FileProgram::FileProgram(const std::string& filepath)
	: m_Stream(filepath)
{
	if (!m_Stream)
	{
		std::cout << "Failed to open file at " << filepath << '\n';
	}
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
		GetLine();
		return false;
	}

	TrimLeadingSpace(m_CurrentLine);
	IgnoreComment();

	std::cout << m_CurrentLine << '\n';

	if (!m_Stream.good())
	{
		return false;
	}

	return true;
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