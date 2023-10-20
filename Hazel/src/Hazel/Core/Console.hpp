#pragma once

#include "Core.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

template<typename... Args>
using format_string_t = std::string_view;

namespace Hazel {

    class Console
    {
    public:
        static void Init();
        static void End();

        template<typename... Args>
        static inline void CoreDebug(format_string_t<Args...> fmt, Args &&... args)
        {
            s_CoreLogger->trace(fmt, std::forward<Args>(args)...);
        }

        template<typename... Args>
        static inline void CoreLog(format_string_t<Args...> fmt, Args &&... args)
        {
            s_CoreLogger->info(fmt, std::forward<Args>(args)...);
        }

        template<typename... Args>
        static inline void CoreWarn(format_string_t<Args...> fmt, Args &&... args)
        {
            s_CoreLogger->warn(fmt, std::forward<Args>(args)...);
        }

        template<typename... Args>
        static inline void CoreError(format_string_t<Args...> fmt, Args &&... args)
        {
            s_CoreLogger->error(fmt, std::forward<Args>(args)...);
        }

        template<typename... Args>
        static inline void CoreCritical(format_string_t<Args...> fmt, Args &&... args)
        {
            s_CoreLogger->critical(fmt, std::forward<Args>(args)...);
        }

        template<typename... Args>
        static inline void Debug(format_string_t<Args...> fmt, Args &&... args)
        {
            s_ClientLogger->trace(fmt, std::forward<Args>(args)...);
        }

        template<typename... Args>
        static inline void Log(format_string_t<Args...> fmt, Args &&... args)
        {
            s_ClientLogger->info(fmt, std::forward<Args>(args)...);
        }

        template<typename... Args>
        static inline void Warn(format_string_t<Args...> fmt, Args &&... args)
        {
            s_ClientLogger->warn(fmt, std::forward<Args>(args)...);
        }

        template<typename... Args>
        static inline void Error(format_string_t<Args...> fmt, Args &&... args)
        {
            s_ClientLogger->error(fmt, std::forward<Args>(args)...);
        }

        template<typename... Args>
        static inline void Critical(format_string_t<Args...> fmt, Args &&... args)
        {
            s_ClientLogger->critical(fmt, std::forward<Args>(args)...);
        }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

}

// Core log macros
//#define HZ_CORE_TRACE(...)    ::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
//#define HZ_CORE_INFO(...)     ::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
//#define HZ_CORE_WARN(...)     ::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
//#define HZ_CORE_ERROR(...)    ::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
//#define HZ_CORE_CRITICAL(...) ::Hazel::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
//#define HZ_TRACE(...)         ::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
//#define HZ_INFO(...)          ::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
//#define HZ_WARN(...)          ::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
//#define HZ_ERROR(...)         ::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
//#define HZ_CRITICAL(...)      ::Hazel::Log::GetClientLogger()->critical(__VA_ARGS__)
