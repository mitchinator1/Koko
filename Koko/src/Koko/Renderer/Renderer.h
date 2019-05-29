#ifndef RENDERER_H
#define RENDERER_H
#include "kkpch.h"
#include "Koko/Core.h"

#include "../Shader/ShaderManager.h"

template <typename T> class Stack;
class Mesh;

namespace Koko
{
	class Layer;

	class Renderer
	{
	private:
		std::unique_ptr<ShaderManager> m_ShaderManager;

	public:
		KK_API Renderer();
		KK_API virtual ~Renderer();

		KK_API void Render(Stack<Layer>& stack);
		KK_API void Render(Mesh* mesh);

	private:
		void RenderMesh(Mesh* mesh);

		void Clear()	const;
		void Prepare()	const;
		void CleanUp()	const;
	};
}

#endif