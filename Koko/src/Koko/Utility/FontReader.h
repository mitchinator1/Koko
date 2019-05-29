#ifndef FONT_READER_H
#define FONT_READER_H
#include <string>
#include <unordered_map>
#include <fstream>

namespace Koko
{
	class FontReader
	{
	private:
		std::ifstream m_Stream;
		std::string m_CurrentLine;

	protected:
		std::unordered_map<std::string, std::string> m_Values;

	public:
		FontReader(const std::string& filepath);
		~FontReader();

		bool LoadFile();
		bool LoadLine();

		auto& GetValues() { return m_Values; }

		void ClearValueCache();

	private:
		void InsertValues(std::string& v1, std::string& v2);
		void TrimLeadingSpace(std::string& value, const char* t = " \t\n\r\f\v");

	};
}

#endif