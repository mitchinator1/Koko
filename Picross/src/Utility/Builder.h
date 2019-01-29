#ifndef BUILDER_H
#define BUILDER_H
#include "FileProgram.h"
#include "Utility/XMLReader.h"
#include "Utility/Node.h"

class Builder
{
protected:
	XML::Reader m_Reader;

public:
	Builder(const std::string& fileName) : m_Reader("Resources/Data/" + fileName + ".data") {}
	virtual ~Builder() {}

	Node GetNode(const std::string& name) { return m_Reader.GetNode(name); }

};

#endif