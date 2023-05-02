#pragma once

#include "April/Core/Layer.h"

#include "April/Events/ApplicationEvent.h"
#include "April/Events/KeyEvent.h"
#include "April/Events/MouseEvent.h"

namespace April {
    class APRIL_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer() = default;

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;
        virtual void OnEvent(Event& event) override;

        void Begin();
        void End();

        void BlockEvents(bool block) { m_BlockEvents = block; }
    private:
        bool m_BlockEvents = true;
        float m_Time = 0.0f;
    };
}