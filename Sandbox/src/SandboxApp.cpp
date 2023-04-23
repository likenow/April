#include <April.h>

class ExampleLayer : public April::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		AL_INFO("ExampleLayer::Update");
	}

	void OnEvent(April::Event& event) override
	{
		AL_TRACE("{0}", event);
	}
};

class Sandbox : public April::Application
{
public:
    Sandbox()
    {
		PushLayer(new ExampleLayer());
	}
    ~Sandbox()
    {}
};

April::Application* April::CreateApplication()
{
    return new Sandbox();
}