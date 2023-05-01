#pragma once
#include "April.h"

#include "ParticleSystem.h"

class Sandbox2D : public April::Layer
{
public:
    Sandbox2D();
    virtual ~Sandbox2D() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void OnUpdate(April::Timestep ts) override;
    virtual void OnImGuiRender() override;
    void OnEvent(April::Event& e) override;
private:
    April::OrthographicCameraController m_CameraController;

    // Temp
    April::Ref<April::VertexArray> m_SquareVA;
    April::Ref<April::Shader> m_FlatColorShader;

    April::Ref<April::Texture2D> m_Texture;

    glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

    ParticleProps m_Particle;
    ParticleSystem m_ParticleSystem;
};