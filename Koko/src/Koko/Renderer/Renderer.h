#ifndef RENDERER_H
#define RENDERER_H
#include "Koko/Core.h"

template <typename T> class Stack;
class Mesh;

namespace Koko
{
	class Layer;

	class Renderer
	{
	public:
		KK_API Renderer();
		KK_API virtual ~Renderer();

		KK_API void Render(Stack<Layer>& stack);
		KK_API void Render(Mesh* mesh);

	private:
		void RenderMesh(Mesh* mesh);

		void Clear()	const;
		void Prepare()	const;
	};
}

#endif