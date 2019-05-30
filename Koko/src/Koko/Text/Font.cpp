#include "kkpch.h"
#include "Font.h"
#include "TextMeshCreator.h"
#include "Koko/Mesh/Texture.h"

namespace Koko
{
	Font::Font(const std::string& name, double width, double height) noexcept
		: m_Name(name)
		, m_Loader(std::make_unique<TextMeshCreator>("Resources/Font/" + name + ".fnt", width, height))
		, m_Texture(new Texture("Resources/Font/" + name + ".png"))
	{

	}

	Font::~Font()
	{

	}

	std::vector<float> Font::LoadText(TextData& data) const
	{
		return m_Loader->CreateVertexData(data);
	}

	Texture* Font::GetTexture()
	{
		return m_Texture;
	}
}