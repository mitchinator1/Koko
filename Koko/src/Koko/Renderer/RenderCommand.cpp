#include "kkpch.h"
#include "Koko/Renderer/RenderCommand.h"

namespace Koko
{

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}