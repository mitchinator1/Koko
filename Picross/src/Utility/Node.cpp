#include "Node.h"

glm::vec2 Node::GetVec2(const std::string& name)
{
	glm::vec2 vector(0.0f, 0.0f);
	
	if (Attributes.find(name) != Attributes.end())
	{
		auto start = Attributes[name].find('"') + 1;
		auto end = Attributes[name].find(',', start);

		std::string value = Attributes[name].substr(start, end - start);
		std::string::size_type sz;

		vector.x = std::stoi(value, &sz);

		start = end + 2;
		end = Attributes[name].find('"', start);
		value = Attributes[name].substr(start, end - start);

		vector.y = std::stoi(value, &sz);
	}

	return vector;
}

glm::vec3 Node::GetVec3(const std::string& name)
{
	glm::vec3 vector(0.0f, 0.0f, 0.0f);

	if (Attributes.find(name) != Attributes.end())
	{
		auto start = Attributes[name].find('"') + 1;
		auto end = Attributes[name].find(',', start);

		std::string value = Attributes[name].substr(start, end - start);
		std::string::size_type sz;

		vector.x = std::stoi(value, &sz);

		start = end + 2;
		end = Attributes[name].find(',', start);
		value = Attributes[name].substr(start, end - start);

		vector.y = std::stoi(value, &sz);

		start = end + 2;
		end = Attributes[name].find('"', start);
		value = Attributes[name].substr(start, end - start);

		vector.z = std::stoi(value, &sz);
	}

	return vector;
}

glm::vec4 Node::GetVec4(const std::string& name)
{
	glm::vec4 vector(0.0f, 0.0f, 0.0f, 0.0f);

	if (Attributes.find(name) != Attributes.end())
	{
		auto start = Attributes[name].find('"') + 1;
		auto end = Attributes[name].find(',', start);

		std::string value = Attributes[name].substr(start, end - start);
		std::string::size_type sz;

		vector.x = std::stoi(value, &sz);

		start = end + 2;
		end = Attributes[name].find(',', start);
		value = Attributes[name].substr(start, end - start);

		vector.y = std::stoi(value, &sz);

		start = end + 2;
		end = Attributes[name].find(',', start);
		value = Attributes[name].substr(start, end - start);

		vector.z = std::stoi(value, &sz);

		start = end + 2;
		end = Attributes[name].find('"', start);
		value = Attributes[name].substr(start, end - start);

		vector.w = std::stoi(value, &sz);
	}

	return vector;
}