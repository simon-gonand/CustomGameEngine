#include "Logger.h"

namespace Engine {
	std::shared_ptr<spdlog::logger> Logger::engineLogger;
	std::shared_ptr<spdlog::logger> Logger::debugLogger;

	void Logger::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		engineLogger = spdlog::stdout_color_mt("Engine");
		engineLogger->set_level(spdlog::level::trace);

		debugLogger = spdlog::stdout_color_mt("Debug");
		debugLogger->set_level(spdlog::level::trace);
	}

	std::shared_ptr<spdlog::logger>& Logger::GetEngineLogger() {
		return engineLogger;
	}

	std::shared_ptr<spdlog::logger>& Logger::GetDebugLogger() {
		return debugLogger;
	}
}
