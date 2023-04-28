#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

#include "April/LayerStack.h"
#include "April/ImGui/ImGuiLayer.h"
#include "April/Renderer/Shader.h"
#include "April/Renderer/Buffer.h"
#include "April/Renderer/VertexArray.h"

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

        std::shared_ptr<Shader> m_Shader;
        std::shared_ptr<VertexArray> m_VertexArray;
        std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;
    private:
        static Application* s_Instance;
    };

    // To be defined in Client
    Application* CreateApplication();
}