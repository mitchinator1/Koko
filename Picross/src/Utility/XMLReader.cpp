#include "XMLReader.h"

namespace XML
{
	void Error::ThrowError(ErrorCode& e, const std::string& fileName)
	{
		switch (e)
		{
		case ErrorCode::None: m_ErrorMsg = "";
			break;
		case ErrorCode::FileNotFound: m_ErrorMsg = fileName + " XML File not found.";
			break;
		case ErrorCode::ElementCloseError: m_ErrorMsg = "Element is not closed properly in " + fileName + ".";
			break;
		default: m_ErrorMsg = "";
			return;
		}
	}

	bool Reader::Load()
	{
		m_FS.open(m_FileName);

		if (m_FS.fail())
		{
			m_Error = Error(ErrorCode::FileNotFound, m_FileName);
			return false;
		}

		return true;
	}

	std::vector<Node> Reader::GetNodes()
	{
		std::vector<Node> nodes;

		return nodes;
	}

	void Reader::GetAttributes(const std::string& line)
	{

	}
}