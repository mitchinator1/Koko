#ifndef XML_READER_H
#define XML_READER_H
#include <string>
#include "FileProgram.h"

struct Node;

namespace XML
{
	enum class ErrorCode
	{
		None = 0,
		FileNotFound,
		ElementCloseError
	};

	class Error
	{
	private:
		std::string m_ErrorMsg = "";

	public:
		Error(ErrorCode err = ErrorCode::None, const std::string& fileName = "")
		{
			ThrowError(err, fileName);
		}

		void ThrowError(ErrorCode& e, const std::string& fileName = "");
		inline std::string ToString() const	{ return m_ErrorMsg; }
	};

	inline std::ostream& operator<<(std::ostream& os, const Error& e)
	{
		return os << e.ToString();
	}

	class Reader
	{
		FileProgram m_File;
		Error m_Error;

	public:
		Reader(const std::string& fileName)
		: m_File(fileName) {}
		~Reader() { m_File.Close(); }

		inline Error GetError() { return m_Error; }

		Node ReadNodes(const std::string& name);

	private:
		Node GetNode();
		Node GetNode(std::string& content);

		void GetAttributes(Node& node);
		void GetAttributes(Node& node, std::string& content);

		std::string GetName();
		std::string GetName(std::string& content);
	};
}

#endif