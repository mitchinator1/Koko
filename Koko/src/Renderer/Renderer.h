#ifndef RENDERER_H
#define RENDERER_H
#include <memory>
#include "Core.h"

template <typename T> class Stack;
class Mesh;
namespace Shader { class ShaderBase; }

namespace Koko
{
	class Layer;

	class KK_API Renderer
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
}

#endif