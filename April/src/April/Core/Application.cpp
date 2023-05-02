#include "alpch.h"
#include "April/Core/Application.h"
#include "April/Core/Layer.h"
#include "April/Renderer/Renderer.h"
#include "April/Core/Input.h"

#include "GLFW/glfw3.h"

namespace April {

    Application* Application::s_Instance = nullptr;

    Application::Application (const std::string& name)
    {
        AL_PROFILE_FUNCTION();
        AL_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;
        m_Window = Window::Create(WindowProps(name));
        m_Window->SetEventCallback(AL_BIND_EVENT_FN(Application::OnEvent));
        Renderer::Init();
        m_ImGuiLayer = new ImGuiLayer();
        PushOverlay(m_ImGuiLayer);
    }

    Application::~Application()
    {
        Renderer::Shutdown();
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent& e)
    {
        AL_PROFILE_FUNCTION();

        if (e.GetWidth() == 0 || e.GetHeight() == 0)
        {
            m_Minimized = true;
            return false;
        }

        m_Minimized = false;
        Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

        return false;
    }

    void Application::Close()
    {
        m_Running = false;
    }

    void Application::OnEvent(Event& e)
    {
        AL_PROFILE_FUNCTION();

        EventDispatcher dispatcher(e);

        dispatcher.Dispatch<WindowCloseEvent>(AL_BIND_EVENT_FN(Application::OnWindowClose));
        dispatcher.Dispatch<WindowResizeEvent>(AL_BIND_EVENT_FN(Application::OnWindowResize));

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
        {
            if (e.Handled)
                break;
            (*--it)->OnEvent(e);
        }
    }

    void Application::Run()
    {
        AL_PROFILE_FUNCTION();
        while (m_Running)
        {
            AL_PROFILE_SCOPE("RunLoop");
            float time = (float)glfwGetTime(); // TODO Platform::GetTime
            Timestep ts = time - m_LastFrameTime;
            m_LastFrameTime = time;

            if (!m_Minimized)
            {
                AL_PROFILE_SCOPE("LayerStack OnUpdate");
                for each (Layer* layer in m_LayerStack)
                {
                    layer->OnUpdate(ts);
                }
            }
            m_ImGuiLayer->Begin();
            {
                AL_PROFILE_SCOPE("LayerStack OnImGuiRender");
                for (Layer* layer : m_LayerStack)
                    layer->OnImGuiRender();
            }
            m_ImGuiLayer->End(); 

            m_Window->OnUpdate();
        }
    }

    void Application::PushLayer(Layer* layer)
    {
        AL_PROFILE_FUNCTION();
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* layer)
    {
        AL_PROFILE_FUNCTION();
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }
}