#include "kkpch.h"
#include "Koko/Renderer/VertexArray.h"

#include "Koko/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Koko
{

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    KK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		KK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}