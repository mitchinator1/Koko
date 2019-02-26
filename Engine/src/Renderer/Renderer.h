#ifndef RENDERER_H
#define RENDERER_H
#include <memory>

template <typename T> class Stack;
class Layer;
class Mesh;
namespace Shader { class ShaderBase; }

class Renderer
{
private:
	std::unique_ptr<Shader::ShaderBase> m_Shader;

public:
	Renderer();
	virtual ~Renderer();

	void Render(Stack<Layer>& stack);

private:
	void RenderMesh(Mesh* mesh);

	void Clear()	const;
	void Prepare()	const;
	void CleanUp()	const;
};

#endif