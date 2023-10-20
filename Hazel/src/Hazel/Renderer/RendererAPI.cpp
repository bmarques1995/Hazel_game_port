#include "hzpch.hpp"
#include "Hazel/Renderer/RendererAPI.hpp"

#include "Platform/OpenGL/OpenGLRendererAPI.hpp"

Hazel::RendererAPI::API Hazel::RendererAPI::s_API = Hazel::RendererAPI::API::OpenGL;

Hazel::Scope<Hazel::RendererAPI> Hazel::RendererAPI::Create()
{
	switch (s_API)
	{
		case RendererAPI::API::None:    HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLRendererAPI>();
	}

	HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
	return nullptr;
}
