#ifndef FONT_TYPE_H
#define FONT_TYPE_H
#include "kkpch.h"

class Texture;

namespace Koko
{
	struct TextData;
	class TextMeshCreator;

	class Font {
	private:
		std::string m_Name;
		std::unique_ptr<TextMeshCreator> m_Loader;
		std::shared_ptr<Texture> m_Texture;

	public:
		Font(const std::string& name = "Arial", double width = 1800.0, double height = 1400.0) noexcept;
		~Font();

		std::vector<float> LoadText(TextData& data)	const;

		std::shared_ptr<Texture>& GetTexture();
		//const std::string& GetName()				const { return m_Name; }

		bool operator==(const Font& rhs)			const
		{
			return (m_Name == rhs.m_Name);
		}
		bool operator==(const std::string& name)	const
		{
			return (m_Name == name);
		}
	};
}

#endif