#include "alpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace April {
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application ()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
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

        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
    }

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        while (m_Running)
        {
            AL_TRACE(e);
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
        while (true);
    }
}