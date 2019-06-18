#ifndef RENDERER_H
#define RENDERER_H

template <typename T> class Stack;
class Mesh;

namespace Koko
{
	class Layer;

	class Renderer
	{
	public:
		Renderer();
		virtual ~Renderer();

		void Render(Stack<Layer>& stack);
		void Render(Mesh* mesh);

	private:
		void RenderMesh(Mesh* mesh);

		void Clear()	const;
		void Prepare()	const;
	};
}

#endif