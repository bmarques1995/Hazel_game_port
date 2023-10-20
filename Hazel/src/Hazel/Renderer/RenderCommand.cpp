#include "hzpch.hpp"
#include "Hazel/Renderer/RenderCommand.hpp"

namespace Hazel {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}