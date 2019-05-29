#include "kkpch.h"
#include "Word.h"

namespace Koko
{
	Word::Word(float fontSize)
		: m_FontSize(fontSize)
	{

	}

	void Word::AddCharacter(Character& character)
	{
		m_Characters.emplace_back(character);
		m_Width += character.xAdvance * m_FontSize;
	}

	std::vector<Character>& Word::GetCharacters()
	{
		return m_Characters;
	}

	float Word::GetWidth()
	{
		return m_Width;
	}
}