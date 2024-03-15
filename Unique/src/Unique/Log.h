#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Unique
{
	class UNQIUE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

//Core Log Macros
#define UQ_CORE_TRACE(...)	::Unique::Log::GetCoreLogger()->trace(__VA_ARGS__) 
#define UQ_CORE_INFO(...)	::Unique::Log::GetCoreLogger()->info(__VA_ARGS__) 
#define UQ_CORE_WARN(...)	::Unique::Log::GetCoreLogger()->warn(__VA_ARGS__) 
#define UQ_CORE_ERROR(...)	::Unique::Log::GetCoreLogger()->error(__VA_ARGS__) 
#define UQ_CORE_FATAL(...)	::Unique::Log::GetCoreLogger()->fatal(__VA_ARGS__) 

//Client Log Macros
#define UQ_TRACE(...)	::Unique::Log::GetClientLogger()->trace(__VA_ARGS__) 
#define UQ_INFO(...)	::Unique::Log::GetClientLogger()->info(__VA_ARGS__) 
#define UQ_WARN(...)	::Unique::Log::GetClientLogger()->warn(__VA_ARGS__) 
#define UQ_ERROR(...)	::Unique::Log::GetClientLogger()->error(__VA_ARGS__) 
#define UQ_FATAL(...)	::Unique::Log::GetClientLogger()->fatal(__VA_ARGS__) 

// If dist build
// #define UQ_CORE_INFO
