#ifndef TEXT_H
#define TEXT_H
#include "kkpch.h"
#include "Koko/Core.h"
#include "Koko/Entity/EntityComponent.h"

#include "Text/Font.h"

namespace Koko
{
	struct TextData
	{
	public:
		std::string Font = "";
		std::string TextString = "";

		unsigned int ID;

		float X, Y, Z, R, G, B, A;
		float Size, XMax, XIndent, YIndent;

		bool Centered, Wrap;

		TextData(const std::string& font, const std::string& text, float size = 1.0f,
			const Position& position = { 0.0f, 0.0f, 0.0f }, const Colour& colour = { 0.0f, 0.0f, 0.0f, 1.0f },
			unsigned int id = 0,
			float xMax = 100.0f, float xIndent = 0.0f, float yIndent = 0.0f,
			bool centered = false, bool wrap = false)
			: Font(font), TextString(text)
			, ID(id)
			, X(position.x), Y(position.y), Z(position.z), R(colour.r), G(colour.g), B(colour.b), A(colour.a)
			, Size(size), XMax(xMax / 100.0f), XIndent(xIndent), YIndent(yIndent)
			, Centered(centered), Wrap(wrap)
		{

		}
	};

	class Text
	{
	private:
		TextData m_Data;
		std::vector<float> m_Vertices;

	public:
		Text() noexcept;
		Text(const TextData& data);
		~Text() {};

		void CreateMesh(std::shared_ptr<Font> font);

		/*virtual void Update();
		virtual bool Continue();

		Text* SetPosition(float x, float y);
		Text* SetSize(float size);
		Text* SetLineSize(float size);
		Text* SetColour(float r, float g, float b);
		Text* SetFont(const std::string& font);
		Text* AddLetter(const std::string& letter);
		Text* RemoveLetter();
		Text* SetCenter(bool centered = true);*/

		void LoadText();

		inline auto GetVertices()			{ return m_Vertices; }
		inline auto GetData()				{ return m_Data; }

	};
}

#endif