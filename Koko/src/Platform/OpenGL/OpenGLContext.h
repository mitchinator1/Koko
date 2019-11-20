#ifndef OPENGL_CONTEXT
#define OPENGL_CONTEXT
#include "Koko/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Koko
{

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* m_WindowHandle;

	};

}


#endif