#include <Hazel.hpp>
#include <Hazel/Core/EntryPoint.hpp>

#include "GameLayer.hpp"

class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new GameLayer());
	}

	~Sandbox()
	{
	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}