#include "hzpch.hpp"
#include "Hazel/Core/Application.hpp"

#include "Hazel/Core/Console.hpp"

#include "Hazel/Renderer/Renderer.hpp"

#include "Hazel/Core/Input.hpp"

#include <glfw/glfw3.h>

Hazel::Application* Hazel::Application::s_Instance = nullptr;

Hazel::Application::Application()
{
	HZ_CORE_ASSERT(!s_Instance, "Application already exists!");
	s_Instance = this;
	m_Window = Window::Create();
	m_Window->SetEventCallback(HZ_BIND_EVENT_FN(Application::OnEvent));

	Renderer::Init();

	m_ImGuiLayer = new ImGuiLayer();
	PushOverlay(m_ImGuiLayer);
}

Hazel::Application::~Application()
{
	Renderer::Shutdown();
}

void Hazel::Application::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
}

void Hazel::Application::PushOverlay(Layer* layer)
{
	m_LayerStack.PushOverlay(layer);
}

void Hazel::Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(HZ_BIND_EVENT_FN(Application::OnWindowClose));
	dispatcher.Dispatch<WindowResizeEvent>(HZ_BIND_EVENT_FN(Application::OnWindowResize));

	for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
	{
		(*it)->OnEvent(e);
		if (e.Handled)
			break;
	}
}

void Hazel::Application::Run()
{
	while (m_Running)
	{
		float time = (float)glfwGetTime();
		Timestep timestep = time - m_LastFrameTime;
		m_LastFrameTime = time;

		if (!m_Minimized)
		{
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate(timestep);
		}

		m_ImGuiLayer->Begin();
		for (Layer* layer : m_LayerStack)
			layer->OnImGuiRender();
		m_ImGuiLayer->End();

		m_Window->OnUpdate();
	}
}

bool Hazel::Application::OnWindowClose(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}

bool Hazel::Application::OnWindowResize(WindowResizeEvent& e)
{
	if (e.GetWidth() == 0 || e.GetHeight() == 0)
	{
		m_Minimized = true;
		return false;
	}

	m_Minimized = false;
	Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

	return false;
}
