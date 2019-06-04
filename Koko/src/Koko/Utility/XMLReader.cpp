#include "kkpch.h"
#include "XMLReader.h"
#include "Node.h"

namespace Koko
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

	Node Reader::ReadNodes(const std::string& name)
	{
		Node node;

		m_File.Load(name, name);
		if (m_File.Empty())
		{
			m_Error = Error(ErrorCode::FileNotFound, name);
			return node;
		}

		m_File.SetStart();
		m_File.SetEndString("</" + name + ">");
		std::string content = m_File.GetSetString();

		node.Name = GetName(content);
		GetAttributes(node, content);

		size_t start = 0;
		size_t end = content.find_first_of('<');

		node.InnerText = content.substr(start, end - start);
		content.erase(start, end);

		while (!content.empty())
		{
			node.ChildNodes.emplace_back(GetNode(content));
		}

		m_File.Close();

		return node;
	}

	Node Reader::GetNode(std::string& content)
	{
		Node node;

		node.Name = GetName(content);
		GetAttributes(node, content);

		size_t start = 0;
		size_t end = content.find_first_of('<');

		node.InnerText = content.substr(start, end - start);
		content.erase(start, end);

		while (content.find("</") >= 2)
		{
			node.ChildNodes.emplace_back(GetNode(content));
		}

		end = content.find_first_of('>') + 1;
		content.erase(start, end);

		return node;
	}

	void Reader::GetAttributes(Node& node, std::string& content)
	{
		size_t start = 0;
		size_t end = content.find_first_of('>') + 1;

		std::stringstream line(content.substr(start, end - start));
		content.erase(start, end);

		while (line)
		{
			std::string name;
			std::getline(line, name, ' ');
			std::getline(line, name, '=');

			if (name == ">")
			{
				break;
			}

			std::string value;
			std::getline(line, value, '"');
			std::getline(line, value, '"');

			node.Attributes.emplace(std::pair(name, value));
		}
	}

	std::string Reader::GetName(std::string& content)
	{
		size_t start = 0;
		size_t end = content.find_first_of('<') + 1;
		content.erase(start, end);

		end = content.find_first_of("> ");

		std::string name = content.substr(start, end - start);
		content.erase(start, end);

		return name;
	}
}