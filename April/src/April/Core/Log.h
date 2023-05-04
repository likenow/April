#pragma once

#include "April/Core/Base.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)


namespace April {
    class APRIL_API Log
    {
    public:
        static void Init();
        inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

        //Log();
        //~Log();
    private:
        static Ref<spdlog::logger> s_CoreLogger;
        static Ref<spdlog::logger> s_ClientLogger;
    };
}

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
    return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
    return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
{
    return os << glm::to_string(quaternion);
}

// Core Log macros
#define AL_CORE_TRACE(...)    ::April::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AL_CORE_INFO(...)     ::April::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AL_CORE_WARN(...)     ::April::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AL_CORE_ERROR(...)    ::April::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AL_CORE_CRITICAL(...) ::April::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log macros
#define AL_TRACE(...)         ::April::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AL_INFO(...)          ::April::Log::GetClientLogger()->info(__VA_ARGS__)
#define AL_WARN(...)          ::April::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AL_ERROR(...)         ::April::Log::GetClientLogger()->error(__VA_ARGS__)
#define AL_CRITICAL(...)      ::April::Log::GetClientLogger()->critical(__VA_ARGS__)