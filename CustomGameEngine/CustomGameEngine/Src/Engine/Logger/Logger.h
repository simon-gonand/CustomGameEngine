#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Engine {
	class Logger
	{
	public: 
		static void Init();
		static std::shared_ptr<spdlog::logger>& GetEngineLogger();
		static std::shared_ptr<spdlog::logger>& GetDebugLogger();

	private:
		static std::shared_ptr<spdlog::logger> engineLogger;
		static std::shared_ptr<spdlog::logger> debugLogger;
	};
}
#define EngineLog(...) Engine::Logger::GetEngineLogger()->trace(__VA_ARGS__)
#define EngineLogError(...) Engine::Logger::GetEngineLogger()->error(__VA_ARGS__)
#define EngineLogInfo(...) Engine::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define EngineLogWarn(...) Engine::Logger::GetEngineLogger()->warn(__VA_ARGS__)

#define DebugLog(...) Engine::Logger::GetDebugLogger()->trace(__VA_ARGS__)
#define DebugLogError(...) Engine::Logger::GetDebugLogger()->error(__VA_ARGS__)
#define DebugLogInfo(...) Engine::Logger::GetDebugLogger()->info(__VA_ARGS__)
#define DebugLogWarn(...) Engine::Logger::GetDebugLogger()->warn(__VA_ARGS__)

