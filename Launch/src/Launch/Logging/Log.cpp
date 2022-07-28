#include "lnpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Launch
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("LAUNCH");
		s_CoreLogger->set_level(spdlog::level::trace);
		LN_CORE_TRACE("Core logger level set to: trace");

		s_ClientLogger = spdlog::stdout_color_mt("CLIENT");
		s_ClientLogger->set_level(spdlog::level::trace);
		LN_TRACE("Client logger level set to: trace");
	}
}