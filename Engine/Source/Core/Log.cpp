#include "Log.h"

namespace ww
{
	std::shared_ptr<spdlog::logger> Log::_EngineLogger;
	std::shared_ptr<spdlog::logger> Log::_AppLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		_EngineLogger = spdlog::stdout_color_mt("ENGINE");
		_EngineLogger->set_level(spdlog::level::trace);

		_AppLogger = spdlog::stdout_color_mt("APP");
		_AppLogger->set_level(spdlog::level::trace);
	}
}