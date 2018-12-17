#ifndef RENDERER_H
#define RENDERER_H
#include <memory>

struct Display;
class Mesh;
namespace Shader { class ShaderBase; }

class Renderer
{
private:
	std::shared_ptr<Display> m_Display;
	std::unique_ptr<Shader::ShaderBase> m_Shader;

public:
	Renderer(std::shared_ptr<Display> display);
	virtual ~Renderer();

	void Render(Mesh* mesh) const;

private:
	void Clear() const;
	void Prepare() const;
	void CleanUp() const;
	void Swap() const;
};

#endif