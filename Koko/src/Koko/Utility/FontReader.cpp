#include "kkpch.h"
#include "FontReader.h"

namespace Koko
{
	FontReader::FontReader(const std::string& filepath)
		: m_Stream(filepath)
	{
		if (!m_Stream)
		{
			std::cout << "Failed to open file at : " << filepath << '\n';
		}
	}

	FontReader::~FontReader()
	{
		if (m_Stream.is_open())
		{
			m_Stream.close();
		}
	}

	bool FontReader::LoadFile()
	{
		while (m_Stream.good())
		{
			LoadLine();
		}

		return true;
	}

	bool FontReader::LoadLine()
	{
		std::getline(m_Stream, m_CurrentLine);
		std::istringstream ss(m_CurrentLine);

		while (ss)
		{
			std::string value1, value2;

			std::getline(ss, value1, '=');
			std::getline(ss, value2, ' ');

			InsertValues(value1, value2);
		}

		if (!m_Stream.good())
			return false;

		return true;
	}

	void FontReader::ClearValueCache()
	{
		m_Values.clear();
	}

	void FontReader::InsertValues(std::string& v1, std::string& v2)
	{
		TrimLeadingSpace(v1);
		TrimLeadingSpace(v2);

		if (v1 == "" || v2 == "")
			return;

		m_Values.insert({ v1, v2 });
	}

	void FontReader::TrimLeadingSpace(std::string& value, const char* t)
	{
		value.erase(0, value.find_first_not_of(t));
	}

}