#include "alpch.h"
#include "Application.h"
#include "April/Core/Layer.h"
#include "April/Renderer/Renderer.h"
#include "Input.h"

#include "GLFW/glfw3.h"

namespace April {

    Application* Application::s_Instance = nullptr;

    Application::Application ()
    {
        AL_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(AL_BIND_EVENT_FN(Application::OnEvent));
        Renderer::Init();
        m_ImGuiLayer = new ImGuiLayer();
        PushOverlay(m_ImGuiLayer);
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return m_Running;
    }

    bool Application::OnWindowResize(WindowResizeEvent& e)
    {
        if (e.GetWidth() == 0 || e.GetHeight() == 0)
        {
            m_Minimized = true;
            return false;
        }

        m_Minimized = false;
        Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

        return false;
    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);

        dispatcher.Dispatch<WindowCloseEvent>(AL_BIND_EVENT_FN(Application::OnWindowClose));
        dispatcher.Dispatch<WindowResizeEvent>(AL_BIND_EVENT_FN(Application::OnWindowResize));

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
        {
            (*--it)->OnEvent(e);
            if (e.Handled)
                break;
        }
    }

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        while (m_Running)
        {
            float time = (float)glfwGetTime(); // TODO Platform::GetTime
            Timestep ts = time - m_LastFrameTime;
            m_LastFrameTime = time;

            if (!m_Minimized)
            {
                for each (Layer* layer in m_LayerStack)
                {
                    layer->OnUpdate(ts);
                }
            }
            m_ImGuiLayer->Begin();
            for (Layer* layer : m_LayerStack)
                layer->OnImGuiRender();
            m_ImGuiLayer->End(); 

            m_Window->OnUpdate();
        }
        while (true);
    }

    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer* layer)
    {
        m_LayerStack.PushOverlay(layer);
    }
}