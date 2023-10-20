#include "hzpch.hpp"
#include "Hazel/Renderer/RenderCommand.hpp"

Hazel::Scope<Hazel::RendererAPI> Hazel::RenderCommand::s_RendererAPI = Hazel::RendererAPI::Create();
