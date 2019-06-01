#include "kkpch.h"
#include "TextManager.h"

namespace Koko
{
	TextManager* TextManager::s_Instance = new TextManager();
	std::unordered_map<std::string, std::unique_ptr<Font>> TextManager::s_Fonts = {};

	bool TextManager::AddFont(const std::string& name)
	{
		if (s_Fonts.find(name) != s_Fonts.end())
		{
			return true;
		}

		s_Fonts.emplace(name, std::make_unique<Font>(name));

		/*if (!s_Fonts[name]->IsValid())
		{
			std::cout << "Font '" << name << "' at '" << filepath << "' not valid.\n";
			s_Fonts.erase(name);
			return false;
		}*/

		return true;
	}

	Font* TextManager::GetFont(const std::string& name)
	{
		if (s_Fonts.find(name) != s_Fonts.end())
		{
			return s_Fonts[name].get();
		}

		return s_Fonts["Text"].get();
	}
}