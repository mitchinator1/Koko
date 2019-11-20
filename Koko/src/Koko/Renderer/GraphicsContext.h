#ifndef GRAPHICS_CONTEXT
#define GRAPHICS_CONTEXT

#include "Koko/Core/Core.h"

namespace Koko
{
	class GraphicsContext
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;

		static Scope<GraphicsContext> Create(void* window);
	};
}

#endif