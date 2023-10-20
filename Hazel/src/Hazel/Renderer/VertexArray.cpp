#include "hzpch.hpp"
#include "Hazel/Renderer/VertexArray.hpp"

#include "Hazel/Renderer/Renderer.hpp"
#include "Platform/OpenGL/OpenGLVertexArray.hpp"

Hazel::Ref<Hazel::VertexArray> Hazel::VertexArray::Create()
{
	switch (Renderer::GetAPI())
	{
		case RendererAPI::API::None:    HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
	}

	HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
	return nullptr;
}
