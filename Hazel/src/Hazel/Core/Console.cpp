#include "hzpch.h"
#include "Console.h"

#include <chrono>
#include <spdlog/sinks/dup_filter_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>

#ifdef HZ_PLATFORM_WINDOWS
#include <spdlog/sinks/msvc_sink.h>
#else
#include <spdlog/sinks/stdout_color_sinks.h>
#endif

namespace Hazel {

	std::shared_ptr<spdlog::logger> Console::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Console::s_ClientLogger;

	void Console::Init()
	{
		std::shared_ptr<spdlog::sinks::dup_filter_sink_mt> client_dup_filter = std::make_shared<spdlog::sinks::dup_filter_sink_mt>(std::chrono::seconds(5));
		std::shared_ptr<spdlog::sinks::dup_filter_sink_mt> core_dup_filter = std::make_shared<spdlog::sinks::dup_filter_sink_mt>(std::chrono::seconds(5));

		std::vector<spdlog::sink_ptr> clientLogSinks;
		std::vector<spdlog::sink_ptr> coreLogSinks;

#ifdef HZ_PLATFORM_WINDOWS
		clientLogSinks.push_back(std::make_shared<spdlog::sinks::msvc_sink_mt>());
		coreLogSinks.push_back(std::make_shared<spdlog::sinks::msvc_sink_mt>());
#else
		clientLogSinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		coreLogSinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
#endif

		clientLogSinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>("client.log", 1024 * 1024, 5, false));
		coreLogSinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>("core.log", 1024 * 1024, 5, false));

		clientLogSinks[0]->set_pattern("%^[%T] %n: %v%$");
		coreLogSinks[0]->set_pattern("%^[%T] %n: %v%$");
		client_dup_filter->add_sink(clientLogSinks[0]);
		core_dup_filter->add_sink(coreLogSinks[0]);

		s_CoreLogger.reset(new spdlog::logger("HAZEL", core_dup_filter));
		spdlog::register_logger(s_CoreLogger);
		s_CoreLogger->set_level(spdlog::level::trace);
		s_CoreLogger->flush_on(spdlog::level::trace);

		s_ClientLogger.reset(new spdlog::logger("APP", client_dup_filter));
		spdlog::register_logger(s_ClientLogger);
		s_ClientLogger->set_level(spdlog::level::trace);
		s_ClientLogger->flush_on(spdlog::level::trace);
	}

	void Console::End()
	{
	}

}