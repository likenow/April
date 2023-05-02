#pragma once

#include "April/Core/Base.h"
#include "April/Core/KeyCodes.h"
#include "April/Core/MouseCodes.h"

namespace April {

    class APRIL_API Input
    {
    public:
        static bool IsKeyPressed(KeyCode key);
        static bool IsMouseButtonPressed(MouseCode button);
        static std::pair<float, float> GetMousePosition();
        static float GetMouseX();
        static float GetMouseY();
    };

}