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