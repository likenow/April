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
        April::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
        //April::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 5.0f, 5.0f }, m_Texture);
        April::Renderer2D::DrawQuad({ -0.5f, -0.5f, -0.1f }, { 10.0f, 10.0f }, m_Texture, 10.0f);
        //April::Renderer2D::DrawQuad({ -0.5f, -0.5f, 0.0f }, { 1.0f, 1.0f }, m_Texture, 20.0f);
        April::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_Texture, 20.0f);
        April::Renderer2D::EndScene();
    }
}

void Sandbox2D::OnImGuiRender()
{
    {
        AL_PROFILE_FUNCTION();
        ImGui::Begin("Settings");
        ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
        ImGui::End();
    }
}

void Sandbox2D::OnEvent(April::Event& e)
{
    m_CameraController.OnEvent(e);
}