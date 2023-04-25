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
        if (April::Input::IsKeyPressed(AL_KEY_TAB))
            AL_TRACE("Tab key is pressed (poll)!");
    }

    void OnEvent(April::Event& event) override
    {
        AL_TRACE("{0}", event);
        if (event.GetEventType() == April::EventType::KeyPressed)
        {
            April::KeyPressedEvent& e = (April::KeyPressedEvent&)event;
            if (e.GetKeyCode() == AL_KEY_TAB)
                AL_TRACE("Tab key is pressed (event)!");
            AL_TRACE("{0}", (char)e.GetKeyCode());
        }
    }
};

class Sandbox : public April::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new April::ImGuiLayer());
    }
    ~Sandbox()
    {}
};

April::Application* April::CreateApplication()
{
    return new Sandbox();
}