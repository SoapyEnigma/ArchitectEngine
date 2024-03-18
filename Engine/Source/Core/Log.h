#pragma once

#include "Defines.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <memory>

namespace ww
{
	class WW_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return _EngineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetAppLogger() { return _AppLogger; }

	private:
		static std::shared_ptr<spdlog::logger> _EngineLogger;
		static std::shared_ptr<spdlog::logger> _AppLogger;
	};
}

#define WW_ENGINE_FATAL(...) ::ww::Log::GetEngineLogger()->fatal(__VA_ARGS__)
#define WW_ENGINE_ERROR(...) ::ww::Log::GetEngineLogger()->error(__VA_ARGS__)
#define WW_ENGINE_WARN(...)  ::ww::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define WW_ENGINE_INFO(...)  ::ww::Log::GetEngineLogger()->info(__VA_ARGS__)
#define WW_ENGINE_TRACE(...) ::ww::Log::GetEngineLogger()->trace(__VA_ARGS__)

#define WW_APP_FATAL(...) ::ww::Log::GetAppLogger()->fatal(__VA_ARGS__)
#define WW_APP_ERROR(...) ::ww::Log::GetAppLogger()->error(__VA_ARGS__)
#define WW_APP_WARN(...)  ::ww::Log::GetAppLogger()->warn(__VA_ARGS__)
#define WW_APP_INFO(...)  ::ww::Log::GetAppLogger()->info(__VA_ARGS__)
#define WW_APP_TRACE(...) ::ww::Log::GetAppLogger()->trace(__VA_ARGS__)