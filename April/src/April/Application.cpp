#include "alpch.h"
#include "Application.h"
#include "April/Layer.h"

#include <glad/glad.h>
#include "Input.h"

namespace April {

    Application* Application::s_Instance = nullptr;

    static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
    {
        switch (type)
        {
        case April::ShaderDataType::Float:    return GL_FLOAT;
        case April::ShaderDataType::Float2:   return GL_FLOAT;
        case April::ShaderDataType::Float3:   return GL_FLOAT;
        case April::ShaderDataType::Float4:   return GL_FLOAT;
        case April::ShaderDataType::Mat3:     return GL_FLOAT;
        case April::ShaderDataType::Mat4:     return GL_FLOAT;
        case April::ShaderDataType::Int:      return GL_INT;
        case April::ShaderDataType::Int2:     return GL_INT;
        case April::ShaderDataType::Int3:     return GL_INT;
        case April::ShaderDataType::Int4:     return GL_INT;
        case April::ShaderDataType::Bool:     return GL_BOOL;
        }

        AL_CORE_ASSERT(false, "Unknown ShaderDataType!");
        return 0;
    }

    Application::Application ()
    {
        AL_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(AL_BIND_EVENT_FN(Application::OnEvent));

        m_ImGuiLayer = new ImGuiLayer();
        PushOverlay(m_ImGuiLayer);

        glGenVertexArrays(1, &m_VertexArray);
        glBindVertexArray(m_VertexArray);

        float vertices[3 * 7] = {
            -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
             0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
             0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
        };

        m_VertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

        {
            BufferLayout layout = {
                { ShaderDataType::Float3, "a_Position" },
                { ShaderDataType::Float4, "a_Color" }
            };

            m_VertexBuffer->SetLayout(layout);
        }

        uint32_t index = 0;
        const auto& layout = m_VertexBuffer->GetLayout();
        for (const auto& element : layout)
        {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index,
                element.GetComponentCount(),
                ShaderDataTypeToOpenGLBaseType(element.Type),
                element.Normalized ? GL_TRUE : GL_FALSE,
                layout.GetStride(),
                (const void*)element.Offset);
            index++;
        }

        uint32_t indices[3] = { 0, 1, 2 };
        m_IndexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));

        std::string vertexSrc = R"(
            #version 330 core
            
            layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec4 a_Color;
            out vec3 v_Position;
            out vec4 v_Color;
            void main()
            {
                v_Position = a_Position;
                v_Color = a_Color;
                gl_Position = vec4(a_Position, 1.0);	
            }
        )";

        std::string fragmentSrc = R"(
            #version 330 core
            
            layout(location = 0) out vec4 color;
            in vec3 v_Position;
            in vec4 v_Color;
            void main()
            {
                color = vec4(v_Position * 0.5 + 0.5, 1.0);
                color = v_Color;
            }
        )";

        m_Shader.reset(new Shader(vertexSrc, fragmentSrc));

    }

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
            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            m_Shader->Bind();
            glBindVertexArray(m_VertexArray);
            glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

            for each (Layer* layer in m_LayerStack)
            {
                layer->OnUpdate();
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