#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Platform/OpenGL/OpenGLShader.h"

Sandbox2D::Sandbox2D()
    : Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
    AL_PROFILE_FUNCTION();
    m_Texture = April::Texture2D::Create("assets/textures/Checkerboard.png");

#if 0
    m_Particle.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
    m_Particle.ColorEnd = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
    m_Particle.SizeBegin = 0.5f, m_Particle.SizeVariation = 0.3f, m_Particle.SizeEnd = 0.0f;
    m_Particle.LifeTime = 1.0f;
    m_Particle.Velocity = { 0.0f, 0.0f };
    m_Particle.VelocityVariation = { 3.0f, 1.0f };
    m_Particle.Position = { 0.0f, 0.0f };
#endif
}

void Sandbox2D::OnDetach()
{
    AL_PROFILE_FUNCTION();

}

void Sandbox2D::OnUpdate(April::Timestep ts)
{
    AL_PROFILE_FUNCTION();
    // Update
    m_CameraController.OnUpdate(ts);

    // Render
    April::Renderer2D::ResetStats();
    {
        AL_PROFILE_SCOPE("Renderer Prep");
        April::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
        April::RenderCommand::Clear();
    }

    {
        AL_PROFILE_SCOPE("Renderer Draw");

        static float rotation = 0.0f;
        rotation += ts * 50.0f;

        April::Renderer2D::BeginScene(m_CameraController.GetCamera());
        April::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
        April::Renderer2D::DrawQuad({ 0.0f, 0.0f }, { 1.0f, 1.0f }, { 0.5f, 0.2f, 0.3f, 1.0f });
        //April::Renderer2D::DrawRotatedQuad({ -0.5f, -0.5f }, { 1.0f, 1.0f }, glm::radians(45.0f), { 0.2f, 0.2f, 0.3f, 1.0f });
        April::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(-45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });
        //April::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 5.0f, 5.0f }, m_Texture);
        April::Renderer2D::DrawQuad({ -0.5f, -0.5f, -0.1f }, { 10.0f, 10.0f }, m_Texture, 10.0f);
        //April::Renderer2D::DrawQuad({ -0.5f, -0.5f, 0.0f }, { 1.0f, 1.0f }, m_Texture, 20.0f);
        April::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, glm::radians(rotation), m_Texture, 20.0f);
        April::Renderer2D::EndScene();

        April::Renderer2D::BeginScene(m_CameraController.GetCamera());
        for (float y = -5.0f; y < 5.0f; y += 0.5f)
        {
            for (float x = -5.0f; x < 5.0f; x += 0.5f)
            {
                glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
                April::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
            }
        }
        April::Renderer2D::EndScene();
    }
#if 0
    if (April::Input::IsMouseButtonPressed(AL_MOUSE_BUTTON_LEFT))
    {
        auto [x, y] = April::Input::GetMousePosition();
        auto width = April::Application::Get().GetWindow().GetWidth();
        auto height = April::Application::Get().GetWindow().GetHeight();

        auto bounds = m_CameraController.GetBounds();
        auto pos = m_CameraController.GetCamera().GetPosition();
        x = (x / width) * bounds.GetWidth() - bounds.GetWidth() * 0.5f;
        y = bounds.GetHeight() * 0.5f - (y / height) * bounds.GetHeight();
        m_Particle.Position = { x + pos.x, y + pos.y };
        for (int i = 0; i < 5; i++)
            m_ParticleSystem.Emit(m_Particle);
    }

    m_ParticleSystem.OnUpdate(ts);
    m_ParticleSystem.OnRender(m_CameraController.GetCamera());
#endif
}

void Sandbox2D::OnImGuiRender()
{
    AL_PROFILE_FUNCTION();
    {
        ImGui::Begin("Settings");

        auto stats = April::Renderer2D::GetStats();
        ImGui::Text("Renderer2D Stats:");
        ImGui::Text("Draw Calls: %d", stats.DrawCalls);
        ImGui::Text("Quads: %d", stats.QuadCount);
        ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
        ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

        ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

        uint32_t textureID = m_Texture->GetRendererID();
        ImGui::Image((void*)textureID, ImVec2{ 1280, 720 });
        ImGui::End();
    }
    {
#if 0
        ImGui::Begin("Settings");
        auto stats = April::Renderer2D::GetStats();
        ImGui::Text("Renderer2D Stats:");
        ImGui::Text("Draw Calls: %d", stats.DrawCalls);
        ImGui::Text("Quads: %d", stats.QuadCount);
        ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
        ImGui::Text("Indices: %d", stats.GetTotalIndexCount());
        ImGui::ColorEdit4("Birth Color", glm::value_ptr(m_Particle.ColorBegin));
        ImGui::ColorEdit4("Death Color", glm::value_ptr(m_Particle.ColorEnd));
        ImGui::DragFloat("Life Time", &m_Particle.LifeTime, 0.1f, 0.0f, 1000.0f);
        ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
        ImGui::End();
#endif
    }
}

void Sandbox2D::OnEvent(April::Event& e)
{
    m_CameraController.OnEvent(e);
}