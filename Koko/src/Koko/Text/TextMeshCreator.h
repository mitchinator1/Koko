#ifndef TEXT_MESH_CREATOR_H
#define TEXT_MESH_CREATOR_H
#include "kkpch.h"

namespace Koko
{
	struct TextData;

	class Line;
	class Word;
	class MetaFile;

	class TextMeshCreator
	{
	private:
		std::unique_ptr<MetaFile> m_MetaData;
		const float LINE_HEIGHT = 0.03f;
		const int SPACE_ASCII = 32;

	public:
		TextMeshCreator(const std::string& filepath = "Resources/Font/Arial.fnt", double width = 1800.0, double height = 1400.0) noexcept;
		~TextMeshCreator();

		std::vector<float> CreateVertexData(TextData& data);

	private:
		std::vector<Line> CreateStructure(TextData& data);
		void CompleteStructure(std::vector<Line>& lines, Line currentLine, Word currentWord);
		std::vector<float> CreateQuadVertices(TextData& data, std::vector<Line>& lines);

	};
}

#endif