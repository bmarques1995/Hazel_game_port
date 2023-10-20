#include "hzpch.hpp"
#include "Hazel/Renderer/Renderer.hpp"
#include "Hazel/Renderer/Renderer2D.hpp"

Hazel::Scope<Hazel::Renderer::SceneData> Hazel::Renderer::s_SceneData = Hazel::CreateScope<Renderer::SceneData>();

void Hazel::Renderer::Init()
{
	RenderCommand::Init();
	Renderer2D::Init();
}

void Hazel::Renderer::Shutdown()
{
	Renderer2D::Shutdown();
}

void Hazel::Renderer::OnWindowResize(uint32_t width, uint32_t height)
{
	RenderCommand::SetViewport(0, 0, width, height);
}

void Hazel::Renderer::BeginScene(OrthographicCamera& camera)
{
	s_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
}

void Hazel::Renderer::EndScene()
{
}

void Hazel::Renderer::Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform)
{
	shader->Bind();
	shader->SetMat4("u_ViewProjection", s_SceneData->ViewProjectionMatrix);
	shader->SetMat4("u_Transform", transform);

	vertexArray->Bind();
	RenderCommand::DrawIndexed(vertexArray);
}
