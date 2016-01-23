#pragma once

#include <core/interfaces/ilogger.h>
#include <core/enums/logger-type.h>
#include <memory>
#include <QString>

namespace Factory {

	class LoggerFactory {
	public:
		explicit LoggerFactory() = delete;
		virtual ~LoggerFactory() = delete;

		static std::unique_ptr<Interface::ILogger> create(const Enum::LoggerType &type, const QString &filePath);
	};

}
