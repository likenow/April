#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

#include "April/LayerStack.h"
#include "April/ImGui/ImGuiLayer.h"

namespace April {
    class APRIL_API Application
    {
    public:
        Application();
        virtual ~Application() = default;

        void OnEvent(Event& e);
        void Run();
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }

        inline static Application& Get() { return *s_Instance; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;

        float m_LastFrameTime = 0.0f;

        
    private:
        static Application* s_Instance;
    };

    // To be defined in Client
    Application* CreateApplication();
}