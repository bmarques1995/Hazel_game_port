#include "hzpch.hpp"
#include "Platform/OpenGL/OpenGLContext.hpp"

#include <GLFW/glfw3.h>
#include <glad/gl.h>
#include <GL/GL.h>

Hazel::OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
	: m_WindowHandle(windowHandle)
{
	HZ_CORE_ASSERT(windowHandle, "Window handle is null!")
}

void Hazel::OpenGLContext::Init()
{
	glfwMakeContextCurrent(m_WindowHandle);
	int status = gladLoadGL((GLADloadfunc)glfwGetProcAddress);
	HZ_CORE_ASSERT(status, "Failed to initialize Glad!");

	//CoreLog
	Console::CoreLog("OpenGL Info:");
	Console::CoreLog("  Vendor: {0}", reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
	Console::CoreLog("  Renderer: {0}", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
	Console::CoreLog("  Version: {0}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));

#ifdef HZ_ENABLE_ASSERTS
	int versionMajor;
	int versionMinor;
	glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
	glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

	HZ_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Hazel requires at least OpenGL version 4.5!");
#endif

	SetVSync(true);
}

void Hazel::OpenGLContext::Present()
{
	glfwSwapBuffers(m_WindowHandle);
}

void Hazel::OpenGLContext::SetVSync(bool enabled)
{
	if (enabled)
		glfwSwapInterval(1);
	else
		glfwSwapInterval(0);

	m_VSync = enabled;
}

bool Hazel::OpenGLContext::IsVSync()
{
	return m_VSync;
}
