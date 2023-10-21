#pragma once

#include "Hazel/Core/Core.hpp"

#include "Hazel/Core/Window.hpp"
#include "Hazel/Renderer/GraphicsContext.hpp"
#include "Hazel/Core/LayerStack.hpp"
#include "Hazel/Events/Event.hpp"
#include "Hazel/Events/ApplicationEvent.hpp"

#include "Hazel/Core/Timestep.hpp"

#include "Hazel/ImGui/ImGuiLayer.hpp"

namespace Hazel {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		Scope<GraphicsContext> m_Context;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}