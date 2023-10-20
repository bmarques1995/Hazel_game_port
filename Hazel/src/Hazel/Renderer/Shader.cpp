#include "hzpch.hpp"
#include "Hazel/Renderer/Shader.hpp"

#include "Hazel/Renderer/Renderer.hpp"
#include "Platform/OpenGL/OpenGLShader.hpp"

Hazel::Ref<Hazel::Shader> Hazel::Shader::Create(const std::string& filepath)
{
	switch (Renderer::GetAPI())
	{
		case RendererAPI::API::None:    HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLShader>(filepath);
	}

	HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
	return nullptr;
}

Hazel::Ref<Hazel::Shader> Hazel::Shader::Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
{
	switch (Renderer::GetAPI())
	{
		case RendererAPI::API::None:    HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLShader>(name, vertexSrc, fragmentSrc);
	}

	HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
	return nullptr;
}

void Hazel::ShaderLibrary::Add(const std::string& name, const Ref<Shader>& shader)
{
	HZ_CORE_ASSERT(!Exists(name), "Shader already exists!");
	m_Shaders[name] = shader;
}

void Hazel::ShaderLibrary::Add(const Ref<Shader>& shader)
{
	auto& name = shader->GetName();
	Add(name, shader);
}

Hazel::Ref<Hazel::Shader> Hazel::ShaderLibrary::Load(const std::string& filepath)
{
	auto shader = Shader::Create(filepath);
	Add(shader);
	return shader;
}

Hazel::Ref<Hazel::Shader> Hazel::ShaderLibrary::Load(const std::string& name, const std::string& filepath)
{
	auto shader = Shader::Create(filepath);
	Add(name, shader);
	return shader;
}

Hazel::Ref<Hazel::Shader> Hazel::ShaderLibrary::Get(const std::string& name)
{
	HZ_CORE_ASSERT(Exists(name), "Shader not found!");
	return m_Shaders[name];
}

bool Hazel::ShaderLibrary::Exists(const std::string& name) const
{
	return m_Shaders.find(name) != m_Shaders.end();
}
