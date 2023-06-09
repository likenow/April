#pragma once
#include "April/Core/Base.h"
#include "April/Events/Event.h"
#include "April/Events/ApplicationEvent.h"
#include "April/Core/Window.h"

#include "April/Core/LayerStack.h"
#include "April/ImGui/ImGuiLayer.h"

namespace April {
    class APRIL_API Application
    {
    public:
        Application(const std::string& name = "April App");
        virtual ~Application();

        void OnEvent(Event& e);
        void Run();
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }
        
        void Close();

        ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }
        inline static Application& Get() { return *s_Instance; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        bool OnWindowResize(WindowResizeEvent& e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        bool m_Minimized = false;
        LayerStack m_LayerStack;

        float m_LastFrameTime = 0.0f;

        
    private:
        static Application* s_Instance;
    };

    // To be defined in Client
    Application* CreateApplication();
}