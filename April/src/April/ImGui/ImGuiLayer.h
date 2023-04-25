#pragma once

#include "April/Layer.h"

#include "April/Events/ApplicationEvent.h"
#include "April/Events/KeyEvent.h"
#include "April/Events/MouseEvent.h"

namespace April {
    class APRIL_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();
    private:
        float m_Time = 0.0f;
    };
}