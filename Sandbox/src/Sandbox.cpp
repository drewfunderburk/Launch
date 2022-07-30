#include <Launch.h>

class ExampleLayer : public Launch::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		LN_INFO("ExampleLayer::Update");
	}

	void OnEvent(Launch::Event& event) override
	{
		LN_TRACE("{0}", event);
	}
};

class Sandbox : public Launch::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{

	}
};

Launch::Application* Launch::CreateApplication()
{
	return new Sandbox();
}