#ifndef XML_READER_H
#define XML_READER_H
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>

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

	struct Node
	{
		std::vector<Node> ChildNodes;
		std::vector<std::unordered_map<std::string, std::string>> Attributes;
		std::string InnerText;
		bool HasChildNode() { return !ChildNodes.empty(); }
	};

	class Reader
	{
		std::string m_FileName;
		std::ifstream m_FS;
		Error m_Error;

	public:
		Reader(const std::string& fileName)
		: m_FileName(fileName) {}
		~Reader() { m_FS.close(); }

		inline Error GetError() { return m_Error; }

		bool Load();
		std::vector<Node> GetNodes();

	private:
		void GetAttributes(const std::string& line);

	};
}

#endif