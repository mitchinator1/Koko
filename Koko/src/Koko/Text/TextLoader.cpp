#include "kkpch.h"
#include "TextLoader.h"
#include "Koko/Utility/Builder.h"

namespace Koko
{
	std::string LoadString(const std::string& key, const std::string& lang)
	{
		Builder builder("MenuText");
		
		auto nodes = builder.GetNodes("Buttons");
		for (auto& node : nodes.ChildNodes)
		{
			for (auto& attrib : node.Attributes)
			{
				if (attrib.second == key)
				{
					for (auto& n : node.ChildNodes)
					{
						if (n.Name == lang)
						{
							return n.InnerText;
						}
					}
				}
			}
		}

		return "Found Nothing";
	}
}