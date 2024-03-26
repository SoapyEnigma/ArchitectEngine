#pragma once

#include "Defines.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>

namespace AE
{
	class AE_API Log
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

#define AE_ENGINE_CRITICAL(...)		::AE::Log::GetEngineLogger()->critical(__VA_ARGS__)
#define AE_ENGINE_ERROR(...)		::AE::Log::GetEngineLogger()->error(__VA_ARGS__)
#define AE_ENGINE_WARN(...)			::AE::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define AE_ENGINE_INFO(...)			::AE::Log::GetEngineLogger()->info(__VA_ARGS__)
#define AE_ENGINE_DEBUG(...)		::AE::Log::GetEngineLogger()->debug(__VA_ARGS__)
#define AE_ENGINE_TRACE(...)		::AE::Log::GetEngineLogger()->trace(__VA_ARGS__)

#define AE_APP_CRITICAL(...)		::AE::Log::GetAppLogger()->critical(__VA_ARGS__)
#define AE_APP_ERROR(...)			::AE::Log::GetAppLogger()->error(__VA_ARGS__)
#define AE_APP_WARN(...)			::AE::Log::GetAppLogger()->warn(__VA_ARGS__)
#define AE_APP_INFO(...)			::AE::Log::GetAppLogger()->info(__VA_ARGS__)
#define AE_APP_DEBUG(...)			::AE::Log::GetAppLogger()->debug(__VA_ARGS__)
#define AE_APP_TRACE(...)			::AE::Log::GetAppLogger()->trace(__VA_ARGS__)