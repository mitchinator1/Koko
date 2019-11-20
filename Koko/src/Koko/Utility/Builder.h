#ifndef BUILDER_H
#define BUILDER_H
#include "FileProgram.h"
#include "Koko/Utility/XMLReader.h"
#include "Koko/Utility/Node.h"

#include "Koko/Core/Core.h"

namespace Koko
{
	class Builder
	{
	protected:
		Reader m_Reader;

	public:
		Builder(const std::string& fileName) : m_Reader("Resources/Data/" + fileName + ".data") {}
		virtual ~Builder() {}

		Node GetNodes(const std::string& name) { return m_Reader.ReadNodes(name); }
	};
}

#endif