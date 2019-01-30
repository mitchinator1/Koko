#include "XMLReader.h"
#include <sstream>
#include "FileProgram.h"
#include "Node.h"

//Temporary
#include <iostream>

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

	Node Reader::GetNode(const std::string& name)
	{
		Node node;

		m_File.Load(name, name);
		if (m_File.Empty())
		{
			return node;
		}

		node.Name = GetName();

		GetAttributes(node);

		while (!m_File.Empty())
		{
			Node childNode;
			std::string end;

			childNode.Name = GetName();
			GetAttributes(childNode);

			while (end.find(childNode.Name) != std::string::npos)
			{
				childNode.ChildNodes.emplace_back(BuildNode());

				m_File.SetStart(0);
				m_File.SetEnd(">", 1);
				end = m_File.GetSetString();

				m_File.SetStart(0);
				m_File.SetEnd(">", 1);
				end = m_File.GetSetString();
			}

			node.ChildNodes.emplace_back(childNode);
		}

		m_File.Close();

		return node;
	}

	void Reader::GetAttributes(Node& node)
	{
		m_File.SetStart(0);
		m_File.SetEnd(">", 1);

		std::stringstream line(m_File.GetSetString());

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

	Node Reader::BuildNode()
	{
		Node node;

		node.Name = GetName();
		
		GetAttributes(node);

		m_File.SetStart(0);
		m_File.SetEnd("<");
		node.InnerText = m_File.GetSetString();

		m_File.SetStart(0);
		m_File.SetEnd(">");
		m_File.GetSetString();

		return node;
	}

	std::string Reader::GetName()
	{
		m_File.SetStart(0);
		m_File.SetEnd("<", 1);
		m_File.GetSetString();

		m_File.SetStart(0);
		m_File.SetEnd("> ");
		
		return m_File.GetSetString();
	}
}