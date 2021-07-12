#include "kkpch.h"
#include "Koko/Core/Core.h"
#include "Koko/Renderer/GraphicsContext.h"

#include "Koko/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Koko
{
	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    KK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		KK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}