#pragma once

#include "Hazel/Core/Layer.hpp"

#include "Hazel/Events/ApplicationEvent.hpp"
#include "Hazel/Events/KeyEvent.hpp"
#include "Hazel/Events/MouseEvent.hpp"

namespace Hazel {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}