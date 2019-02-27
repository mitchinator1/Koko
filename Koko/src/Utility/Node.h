#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>
#include <unordered_map>

#include "GLM/vec2.hpp"
#include "GLM/vec3.hpp"
#include "GLM/vec4.hpp"

namespace Koko
{
	struct Node
	{
		bool IsOpen = true;
		std::vector<Node> ChildNodes;
		std::unordered_map<std::string, std::string> Attributes;
		std::string Name;
		std::string InnerText;

		std::string GetValue(const std::string& name);
		glm::vec2 GetVec2(const std::string& name);
		glm::vec3 GetVec3(const std::string& name);
		glm::vec4 GetVec4(const std::string& name);
	};
}

#endif