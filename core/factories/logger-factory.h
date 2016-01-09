#pragma once

#include <core/interfaces/ilogger.h>
#include <core/enums/logger-type-enum.h>
#include <memory>

namespace Factory {

	class LoggerFactory {
	public:
		explicit LoggerFactory() = delete;
		virtual ~LoggerFactory() = delete;

		static std::unique_ptr<Interface::ILogger> create(const Enum::LoggerType &type);
	};

}
