#include "alpch.h"
#include "Application.h"
#include "April/Layer.h"

#include <glad/glad.h>

namespace April {

    Application* Application::s_Instance = nullptr;

    Application::Application ()
    {
        AL_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(AL_BIND_EVENT_FN(Application::OnEvent));
    }

    Application::~Application()
    {}

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return m_Running;
    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);

        dispatcher.Dispatch<WindowCloseEvent>(AL_BIND_EVENT_FN(Application::OnWindowClose));

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
            AL_TRACE(e);
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            for each (Layer* layer in m_LayerStack)
            {
                layer->OnUpdate();
            }
            m_Window->OnUpdate();
        }
        while (true);
    }

    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* layer)
    {
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }
}