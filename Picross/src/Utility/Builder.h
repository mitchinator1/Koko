#ifndef BUILDER_H
#define BUILDER_H
#include "FileProgram.h"

class Builder
{
protected:
	FileProgram m_File;

public:
	Builder(const std::string& fileName) : m_File("Resources/Data/" + fileName + ".data") {}
	virtual ~Builder() {}

	//TODO: Set up file reading from builder base class
	std::string GetPair() 
	{
		if (m_File.LoadLine())
		{
			return m_File.GetLine();
		}

		return "";
	}

	inline glm::vec2 GetVec2(const std::string& v) { return m_File.GetVec2(v); }
	inline glm::vec4 GetVec4(const std::string& v) { return m_File.GetVec4(v); }

	inline bool FindTrait(const std::string& target) { return m_File.FindTrait(target); }

};

#endif