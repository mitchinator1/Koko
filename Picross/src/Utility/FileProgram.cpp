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

bool FileProgram::LoadLine()
{
	std::getline(m_Stream, m_CurrentLine);

	if (m_CurrentLine.size() == 0)
	{
		LoadLine();
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

bool FileProgram::FindTrait(const std::string& target)
{
	if (m_CurrentLine.find(target) != std::string::npos)
	{
		return true;
	}

	return false;
}

glm::vec2 FileProgram::GetVec2(const std::string& v)
{
	glm::vec2 vector(0.0f, 0.0f);

	if (m_CurrentLine.find(v) != std::string::npos)
	{
		auto start = m_CurrentLine.find('"', m_CurrentLine.find(v)) + 1;
		auto end = m_CurrentLine.find(',', start);

		std::string value = m_CurrentLine.substr(start, end - start);
		std::string::size_type sz;

		vector.x = std::stoi(value, &sz);

		start = end + 2;
		end = m_CurrentLine.find('"', start);

		value = m_CurrentLine.substr(start, end - start);
		vector.y = std::stoi(value, &sz);
	}

	return vector;
}

glm::vec4 FileProgram::GetVec4(const std::string& v)
{
	glm::vec4 vector(0.0f, 0.0f, 0.0f, 0.0f);

	if (m_CurrentLine.find(v) != std::string::npos)
	{
		auto start = m_CurrentLine.find('"', m_CurrentLine.find(v)) + 1;
		auto end = m_CurrentLine.find(',', start);

		std::string value = m_CurrentLine.substr(start, end - start);
		std::string::size_type sz;

		vector.x = std::stoi(value, &sz);

		start = end + 2;
		end = m_CurrentLine.find(',', start);

		value = m_CurrentLine.substr(start, end - start);
		vector.y = std::stoi(value, &sz);

		start = end + 2;
		end = m_CurrentLine.find(',', start);

		value = m_CurrentLine.substr(start, end - start);
		vector.z = std::stoi(value, &sz);

		start = end + 2;
		end = m_CurrentLine.find('"', start);

		value = m_CurrentLine.substr(start, end - start);
		vector.w = std::stoi(value, &sz);
	}

	return vector;
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