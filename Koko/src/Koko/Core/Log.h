#ifndef LOG_H
#define LOG_H

#include "Koko/Core/Core.h"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Koko {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define KK_CORE_TRACE(...)    ::Koko::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KK_CORE_INFO(...)     ::Koko::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KK_CORE_WARN(...)     ::Koko::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KK_CORE_ERROR(...)    ::Koko::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KK_CORE_CRITICAL(...) ::Koko::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define KK_TRACE(...)         ::Koko::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KK_INFO(...)          ::Koko::Log::GetClientLogger()->info(__VA_ARGS__)
#define KK_WARN(...)          ::Koko::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KK_ERROR(...)         ::Koko::Log::GetClientLogger()->error(__VA_ARGS__)
#define KK_CRITICAL(...)      ::Koko::Log::GetClientLogger()->critical(__VA_ARGS__)

#endif