#ifndef TEXT_MANAGER
#define TEXT_MANAGER
#include "kkpch.h"
#include "Koko/Core.h"
#include "Font.h"

namespace Koko
{
	class TextManager
	{
	private:
		static TextManager* s_Instance;
		static std::unordered_map<std::string, std::unique_ptr<Font>> s_Fonts;

		TextManager() {};
		
	public:
		KK_API static bool AddFont(const std::string& name);
		KK_API static Font* GetFont(const std::string& name);

	};
}

#endif