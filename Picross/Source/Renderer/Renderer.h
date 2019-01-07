#ifndef RENDERER_H
#define RENDERER_H
#include <memory>
#include "../LayerStack.h"

class Mesh;
namespace Shader { class ShaderBase; }

class Renderer
{
private:
	std::unique_ptr<Shader::ShaderBase> m_Shader;

public:
	Renderer();
	virtual ~Renderer();

	void Render(LayerStack& layers);

private:
	void RenderMesh(Mesh* mesh);

	void Clear()	const;
	void Prepare()	const;
	void CleanUp()	const;
};

#endif