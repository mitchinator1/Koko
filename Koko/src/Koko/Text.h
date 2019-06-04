#ifndef TEXT_H
#define TEXT_H

namespace Koko
{
	struct TextData
	{
	public:
		std::string Font;
		std::string TextString;

		unsigned int ID;

		float X, Y, Z, R, G, B;
		float Size, XMax; //TODO: Remove XMAX
		//Alignment (Left, Right, Center)
		//Anchor (point for rotation)

		bool Centered, Wrap;

		TextData(const std::string& font = "", const std::string& text = "", float size = 1.0f,
			float x = 0.0f, float y = 0.0f, float z = 0.0f, float r = 1.0f, float g = 1.0f, float b = 1.0f,
			unsigned int id = 0, float xMax = 100.0f, bool centered = false, bool wrap = false)
			: Font(font), TextString(text), Size(size)
			, X(x), Y(y), Z(z), R(r), G(g), B(b)
			, ID(id), XMax(xMax / 100.0f)
			, Centered(centered), Wrap(wrap)
		{

		}
	};

	class Text
	{
	private:
		TextData m_Data;
		std::vector<float> m_Vertices;

		bool m_Created;

	public:
		Text() noexcept;
		Text(const TextData& data);
		~Text() {};

		void CreateMesh();

		/*virtual void Update();
		virtual bool Continue();

		Text* SetLineSize(float size);
		Text* AddLetter(const std::string& letter);
		Text* RemoveLetter();*/

		inline auto& GetVertices()			{ return m_Vertices; }
		inline auto& GetData()				{ return m_Data; }
		inline auto IsCreated()				{ return m_Created; }

	private:
		void LoadText();
	};

}

#endif