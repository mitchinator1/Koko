#include "kkpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include <GL/GL.h>

namespace Koko
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		KK_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		KK_CORE_ASSERT(status, "Failed to initialize Glad!");

		KK_CORE_INFO("OpenGL Info:");
		KK_CORE_INFO(" Vendor: {0}", glGetString(GL_VENDOR));
		KK_CORE_INFO(" Renderer: {0}", glGetString(GL_RENDERER));
		KK_CORE_INFO(" Version: {0}", glGetString(GL_VERSION));
		
		KK_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && glVersion.minor >= 5), "Koko requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}