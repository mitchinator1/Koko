#ifndef TEXT_MANAGER
#define TEXT_MANAGER
#include "Koko/Core/Core.h"
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
		static bool AddFont(const std::string& name);
		static Font* GetFont(const std::string& name);

	};
}

#endif