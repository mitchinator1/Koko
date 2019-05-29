#ifndef LINE_H
#define LINE_H
#include "Word.h"

namespace Koko
{
	class Line {
	private:
		float m_MaxLength;
		float m_SpaceSize;

		std::vector<Word> m_Words;
		float m_CurrentLineLength = 0.0f;

	public:
		Line(float spaceWidth, float fontSize, float maxLength);

		bool AttemptToAddWord(Word& word);
		float GetMaxLength();
		float GetLineLength();
		std::vector<Word>& GetWords();

		Line operator()(const Line& rhs)
		{
			m_SpaceSize = rhs.m_SpaceSize;
			m_MaxLength = rhs.m_MaxLength;
			return *this;
		}
	};
}

#endif