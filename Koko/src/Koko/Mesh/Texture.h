#ifndef TEXTURE_H
#define TEXTURE_H

class Texture
{
private:
	unsigned int m_TextureID;

public:
	Texture(const std::string& filename);
	~Texture();
	
	void Bind() const;
	void Unbind() const;

	inline unsigned int GetTexture() const { return m_TextureID; }

private:
	void LoadImageFromFile(const std::string& filepath);
};

#endif