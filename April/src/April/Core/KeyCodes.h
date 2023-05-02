#pragma once

namespace April
{
    typedef enum class KeyCode : uint16_t
    {
        // From glfw3.h
        Space = 32,
        Apostrophe = 39, /* ' */
        Comma = 44, /* , */
        Minus = 45, /* - */
        Period = 46, /* . */
        Slash = 47, /* / */

        D0 = 48, /* 0 */
        D1 = 49, /* 1 */
        D2 = 50, /* 2 */
        D3 = 51, /* 3 */
        D4 = 52, /* 4 */
        D5 = 53, /* 5 */
        D6 = 54, /* 6 */
        D7 = 55, /* 7 */
        D8 = 56, /* 8 */
        D9 = 57, /* 9 */

        Semicolon = 59, /* ; */
        Equal = 61, /* = */

        A = 65,
        B = 66,
        C = 67,
        D = 68,
        E = 69,
        F = 70,
        G = 71,
        H = 72,
        I = 73,
        J = 74,
        K = 75,
        L = 76,
        M = 77,
        N = 78,
        O = 79,
        P = 80,
        Q = 81,
        R = 82,
        S = 83,
        T = 84,
        U = 85,
        V = 86,
        W = 87,
        X = 88,
        Y = 89,
        Z = 90,

        LeftBracket = 91,  /* [ */
        Backslash = 92,  /* \ */
        RightBracket = 93,  /* ] */
        GraveAccent = 96,  /* ` */

        World1 = 161, /* non-US #1 */
        World2 = 162, /* non-US #2 */

        /* Function keys */
        Escape = 256,
        Enter = 257,
        Tab = 258,
        Backspace = 259,
        Insert = 260,
        Delete = 261,
        Right = 262,
        Left = 263,
        Down = 264,
        Up = 265,
        PageUp = 266,
        PageDown = 267,
        Home = 268,
        End = 269,
        CapsLock = 280,
        ScrollLock = 281,
        NumLock = 282,
        PrintScreen = 283,
        Pause = 284,
        F1 = 290,
        F2 = 291,
        F3 = 292,
        F4 = 293,
        F5 = 294,
        F6 = 295,
        F7 = 296,
        F8 = 297,
        F9 = 298,
        F10 = 299,
        F11 = 300,
        F12 = 301,
        F13 = 302,
        F14 = 303,
        F15 = 304,
        F16 = 305,
        F17 = 306,
        F18 = 307,
        F19 = 308,
        F20 = 309,
        F21 = 310,
        F22 = 311,
        F23 = 312,
        F24 = 313,
        F25 = 314,

        /* Keypad */
        KP0 = 320,
        KP1 = 321,
        KP2 = 322,
        KP3 = 323,
        KP4 = 324,
        KP5 = 325,
        KP6 = 326,
        KP7 = 327,
        KP8 = 328,
        KP9 = 329,
        KPDecimal = 330,
        KPDivide = 331,
        KPMultiply = 332,
        KPSubtract = 333,
        KPAdd = 334,
        KPEnter = 335,
        KPEqual = 336,

        LeftShift = 340,
        LeftControl = 341,
        LeftAlt = 342,
        LeftSuper = 343,
        RightShift = 344,
        RightControl = 345,
        RightAlt = 346,
        RightSuper = 347,
        Menu = 348
    } Key;

    inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
    {
        os << static_cast<int32_t>(keyCode);
        return os;
    }
}

// From glfw3.h
#define AL_KEY_SPACE           ::April::Key::Space
#define AL_KEY_APOSTROPHE      ::April::Key::Apostrophe    /* ' */
#define AL_KEY_COMMA           ::April::Key::Comma         /* , */
#define AL_KEY_MINUS           ::April::Key::Minus         /* - */
#define AL_KEY_PERIOD          ::April::Key::Period        /* . */
#define AL_KEY_SLASH           ::April::Key::Slash         /* / */
#define AL_KEY_0               ::April::Key::D0
#define AL_KEY_1               ::April::Key::D1
#define AL_KEY_2               ::April::Key::D2
#define AL_KEY_3               ::April::Key::D3
#define AL_KEY_4               ::April::Key::D4
#define AL_KEY_5               ::April::Key::D5
#define AL_KEY_6               ::April::Key::D6
#define AL_KEY_7               ::April::Key::D7
#define AL_KEY_8               ::April::Key::D8
#define AL_KEY_9               ::April::Key::D9
#define AL_KEY_SEMICOLON       ::April::Key::Semicolon     /* ; */
#define AL_KEY_EQUAL           ::April::Key::Equal         /* = */
#define AL_KEY_A               ::April::Key::A
#define AL_KEY_B               ::April::Key::B
#define AL_KEY_C               ::April::Key::C
#define AL_KEY_D               ::April::Key::D
#define AL_KEY_E               ::April::Key::E
#define AL_KEY_F               ::April::Key::F
#define AL_KEY_G               ::April::Key::G
#define AL_KEY_H               ::April::Key::H
#define AL_KEY_I               ::April::Key::I
#define AL_KEY_J               ::April::Key::J
#define AL_KEY_K               ::April::Key::K
#define AL_KEY_L               ::April::Key::L
#define AL_KEY_M               ::April::Key::M
#define AL_KEY_N               ::April::Key::N
#define AL_KEY_O               ::April::Key::O
#define AL_KEY_P               ::April::Key::P
#define AL_KEY_Q               ::April::Key::Q
#define AL_KEY_R               ::April::Key::R
#define AL_KEY_S               ::April::Key::S
#define AL_KEY_T               ::April::Key::T
#define AL_KEY_U               ::April::Key::U
#define AL_KEY_V               ::April::Key::V
#define AL_KEY_W               ::April::Key::W
#define AL_KEY_X               ::April::Key::X
#define AL_KEY_Y               ::April::Key::Y
#define AL_KEY_Z               ::April::Key::Z
#define AL_KEY_LEFT_BRACKET    ::April::Key::LeftBracket   /* [ */
#define AL_KEY_BACKSLASH       ::April::Key::Backslash     /* \ */
#define AL_KEY_RIGHT_BRACKET   ::April::Key::RightBracket  /* ] */
#define AL_KEY_GRAVE_ACCENT    ::April::Key::GraveAccent   /* ` */
#define AL_KEY_WORLD_1         ::April::Key::World1        /* non-US #1 */
#define AL_KEY_WORLD_2         ::April::Key::World2        /* non-US #2 */

/* Function keys */
#define AL_KEY_ESCAPE          ::April::Key::Escape
#define AL_KEY_ENTER           ::April::Key::Enter
#define AL_KEY_TAB             ::April::Key::Tab
#define AL_KEY_BACKSPACE       ::April::Key::Backspace
#define AL_KEY_INSERT          ::April::Key::Insert
#define AL_KEY_DELETE          ::April::Key::Delete
#define AL_KEY_RIGHT           ::April::Key::Right
#define AL_KEY_LEFT            ::April::Key::Left
#define AL_KEY_DOWN            ::April::Key::Down
#define AL_KEY_UP              ::April::Key::Up
#define AL_KEY_PAGE_UP         ::April::Key::PageUp
#define AL_KEY_PAGE_DOWN       ::April::Key::PageDown
#define AL_KEY_HOME            ::April::Key::Home
#define AL_KEY_END             ::April::Key::End
#define AL_KEY_CAPS_LOCK       ::April::Key::CapsLock
#define AL_KEY_SCROLL_LOCK     ::April::Key::ScrollLock
#define AL_KEY_NUM_LOCK        ::April::Key::NumLock
#define AL_KEY_PRINT_SCREEN    ::April::Key::PrintScreen
#define AL_KEY_PAUSE           ::April::Key::Pause
#define AL_KEY_F1              ::April::Key::F1
#define AL_KEY_F2              ::April::Key::F2
#define AL_KEY_F3              ::April::Key::F3
#define AL_KEY_F4              ::April::Key::F4
#define AL_KEY_F5              ::April::Key::F5
#define AL_KEY_F6              ::April::Key::F6
#define AL_KEY_F7              ::April::Key::F7
#define AL_KEY_F8              ::April::Key::F8
#define AL_KEY_F9              ::April::Key::F9
#define AL_KEY_F10             ::April::Key::F10
#define AL_KEY_F11             ::April::Key::F11
#define AL_KEY_F12             ::April::Key::F12
#define AL_KEY_F13             ::April::Key::F13
#define AL_KEY_F14             ::April::Key::F14
#define AL_KEY_F15             ::April::Key::F15
#define AL_KEY_F16             ::April::Key::F16
#define AL_KEY_F17             ::April::Key::F17
#define AL_KEY_F18             ::April::Key::F18
#define AL_KEY_F19             ::April::Key::F19
#define AL_KEY_F20             ::April::Key::F20
#define AL_KEY_F21             ::April::Key::F21
#define AL_KEY_F22             ::April::Key::F22
#define AL_KEY_F23             ::April::Key::F23
#define AL_KEY_F24             ::April::Key::F24
#define AL_KEY_F25             ::April::Key::F25

/* Keypad */
#define AL_KEY_KP_0            ::April::Key::KP0
#define AL_KEY_KP_1            ::April::Key::KP1
#define AL_KEY_KP_2            ::April::Key::KP2
#define AL_KEY_KP_3            ::April::Key::KP3
#define AL_KEY_KP_4            ::April::Key::KP4
#define AL_KEY_KP_5            ::April::Key::KP5
#define AL_KEY_KP_6            ::April::Key::KP6
#define AL_KEY_KP_7            ::April::Key::KP7
#define AL_KEY_KP_8            ::April::Key::KP8
#define AL_KEY_KP_9            ::April::Key::KP9
#define AL_KEY_KP_DECIMAL      ::April::Key::KPDecimal
#define AL_KEY_KP_DIVIDE       ::April::Key::KPDivide
#define AL_KEY_KP_MULTIPLY     ::April::Key::KPMultiply
#define AL_KEY_KP_SUBTRACT     ::April::Key::KPSubtract
#define AL_KEY_KP_ADD          ::April::Key::KPAdd
#define AL_KEY_KP_ENTER        ::April::Key::KPEnter
#define AL_KEY_KP_EQUAL        ::April::Key::KPEqual

#define AL_KEY_LEFT_SHIFT      ::April::Key::LeftShift
#define AL_KEY_LEFT_CONTROL    ::April::Key::LeftControl
#define AL_KEY_LEFT_ALT        ::April::Key::LeftAlt
#define AL_KEY_LEFT_SUPER      ::April::Key::LeftSuper
#define AL_KEY_RIGHT_SHIFT     ::April::Key::RightShift
#define AL_KEY_RIGHT_CONTROL   ::April::Key::RightControl
#define AL_KEY_RIGHT_ALT       ::April::Key::RightAlt
#define AL_KEY_RIGHT_SUPER     ::April::Key::RightSuper
#define AL_KEY_MENU            ::April::Key::Menu