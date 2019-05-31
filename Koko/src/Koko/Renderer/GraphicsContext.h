#ifndef GRAPHICS_CONTEXT
#define GRAPHICS_CONTEXT

namespace Koko
{
	class GraphicsContext
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	};
}

#endif