#include "kkpch.h"
#include "TextMeshCreator.h"
#include "Koko/Text.h"
#include "Line.h"
#include "MetaFile.h"

namespace Koko
{
	TextMeshCreator::TextMeshCreator(const std::string& filepath, double width, double height) noexcept
		: m_MetaData(std::make_unique<MetaFile>(filepath, width, height))
	{

	}

	TextMeshCreator::~TextMeshCreator()
	{

	}

	std::vector<float> TextMeshCreator::CreateVertexData(TextData& data)
	{
		auto lines = CreateStructure(data);
		return CreateQuadVertices(data, lines);
	}

	std::vector<Line> TextMeshCreator::CreateStructure(TextData& data)
	{
		std::vector<Line> lines;
		Line currentLine(m_MetaData->GetSpaceWidth(), data.Size, data.XMax);
		Word currentWord(data.Size);

		std::string chars = data.TextString;
		for (char& c : chars)
		{
			int ascii = (int)c;
			if (ascii == SPACE_ASCII)
			{
				if (!currentLine.AttemptToAddWord(currentWord))
				{
					lines.emplace_back(currentLine);
					currentLine = Line(currentLine);
					currentLine.AttemptToAddWord(currentWord);
				}
				currentWord = Word(data.Size);
				continue;
			}
			currentWord.AddCharacter(m_MetaData->GetCharacter(ascii));
		}
		CompleteStructure(lines, currentLine, currentWord);
		return lines;
	}

	void TextMeshCreator::CompleteStructure(std::vector<Line>& lines, Line currentLine, Word currentWord)
	{
		if (!currentLine.AttemptToAddWord(currentWord))
		{
			lines.emplace_back(currentLine);
			currentLine = Line(currentLine);
			currentLine.AttemptToAddWord(currentWord);
		}
		lines.emplace_back(currentLine);
	}

	std::vector<float> TextMeshCreator::CreateQuadVertices(TextData& data, std::vector<Line>& lines)
	{
		glm::vec3 cursor = { data.X / 100.0f, data.Y / 100.0f, data.Z / 100.0f };
		glm::vec4 colour = { data.R, data.G, data.B, data.A };
		std::vector<float> vertices;
		for (Line& line : lines)
		{
			if (data.Centered)
			{
				cursor.x = cursor.x + (line.GetMaxLength() - line.GetLineLength()) / 2.0f;
			}
			float fontSize = data.Size;
			for (Word& word : line.GetWords())
			{
				float z = cursor.z;
				for (Character& letter : word.GetCharacters())
				{
					float minX = cursor.x + (letter.xOffset * fontSize);
					float minY = cursor.y + (letter.yOffset * fontSize);
					float maxX = minX + (letter.xSize * fontSize);
					float maxY = minY + (letter.ySize * fontSize);
					minX = minX * 2.0f - 1.0f;
					minY = -minY * 2.0f + 1.0f;
					maxX = maxX * 2.0f - 1.0f;
					maxY = -maxY * 2.0f + 1.0f;
					vertices.insert(vertices.end(), {
						minX,	minY,	z,	letter.xTextureCoord,	 letter.yTextureCoord,		colour.r, colour.g, colour.b,
						minX,	maxY,	z,	letter.xTextureCoord,	 letter.yMaxTextureCoord,	colour.r, colour.g, colour.b,
						maxX,	maxY,	z,	letter.xMaxTextureCoord, letter.yMaxTextureCoord,	colour.r, colour.g, colour.b,
						maxX,	minY,	z,	letter.xMaxTextureCoord, letter.yTextureCoord,		colour.r, colour.g, colour.b
						});
					cursor.x += letter.xAdvance * fontSize;
					z -= 0.001f;
				}
				cursor.x += (m_MetaData->GetSpaceWidth() * fontSize);
			}
			cursor.x = 0.0f;
			cursor.y += LINE_HEIGHT * fontSize;
		}
		return vertices;
	}
}