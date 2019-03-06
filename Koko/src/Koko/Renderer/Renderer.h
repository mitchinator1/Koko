#ifndef RENDERER_H
#define RENDERER_H
#include "kkpch.h"
#include "Koko/Core.h"

template <typename T> class Stack;
class Mesh;
namespace Shader { class ShaderBase; }

namespace Koko
{
	class Layer;

	class Renderer
	{
	private:
		std::unique_ptr<Shader::ShaderBase> m_Shader;

	public:
		KK_API Renderer();
		KK_API virtual ~Renderer();

		KK_API void Render(Stack<Layer>& stack);

	private:
		void RenderMesh(Mesh* mesh);

		void Clear()	const;
		void Prepare()	const;
		void CleanUp()	const;
	};
}

#endif