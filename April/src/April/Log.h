#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace April {
	class APRIL_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		//Log();
		//~Log();
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log macros
#define AL_CORE_TRACE(...) ::April::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AL_CORE_INFO(...)  ::April::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AL_CORE_WARN(...)  ::April::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AL_CORE_ERROR(...) ::April::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AL_CORE_FATAL(...) ::April::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros
#define AL_TRACE(...) ::April::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AL_INFO(...)  ::April::Log::GetClientLogger()->info(__VA_ARGS__)
#define AL_WARN(...)  ::April::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AL_ERROR(...) ::April::Log::GetClientLogger()->error(__VA_ARGS__)
#define AL_FATAL(...) ::April::Log::GetClientLogger()->fatal(__VA_ARGS__)