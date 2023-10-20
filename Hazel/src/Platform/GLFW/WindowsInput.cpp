#include "hzpch.hpp"
#include "Platform/GLFW/WindowsInput.hpp"

#include "Hazel/Core/Application.hpp"
#include <GLFW/glfw3.h>

Hazel::Scope<Hazel::Input> Hazel::Input::s_Instance = Hazel::CreateScope<WindowsInput>();

bool Hazel::WindowsInput::IsKeyPressedImpl(int keycode)
{
	auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
	auto state = glfwGetKey(window, keycode);
	return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool Hazel::WindowsInput::IsMouseButtonPressedImpl(int button)
{
	auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
	auto state = glfwGetMouseButton(window, button);
	return state == GLFW_PRESS;
}

std::pair<float, float> Hazel::WindowsInput::GetMousePositionImpl()
{
	auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	return { (float)xpos, (float)ypos };
}

float Hazel::WindowsInput::GetMouseXImpl()
{
	auto[x, y] = GetMousePositionImpl();
	return x;
}

float Hazel::WindowsInput::GetMouseYImpl()
{
	auto[x, y] = GetMousePositionImpl();
	return y;
}
