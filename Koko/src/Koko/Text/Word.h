#ifndef WORD_H
#define WORD_H
#include "kkpch.h"
#include "Character.h"

namespace Koko
{
	class Word {
	private:
		std::vector<Character> m_Characters;
		float m_Width = 0;
		float m_FontSize;

	public:
		Word(float fontSize);

		void AddCharacter(Character& character);
		std::vector<Character>& GetCharacters();
		float GetWidth();
	};
}

#endif