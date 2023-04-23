#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

#include "April/LayerStack.h"

namespace April {
    class APRIL_API Application
    {
    public:
        Application();
        virtual ~Application();

        void OnEvent(Event& e);
        void Run();
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

    // To be defined in Client
    Application* CreateApplication();
}