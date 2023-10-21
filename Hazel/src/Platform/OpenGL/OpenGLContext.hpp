#pragma once

#include "Hazel/Renderer/GraphicsContext.hpp"

struct GLFWwindow;

namespace Hazel {

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void Present() override;

		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() override;
	private:
		GLFWwindow* m_WindowHandle;
		bool m_VSync = false;
	};

}