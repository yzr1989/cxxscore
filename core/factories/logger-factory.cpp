#include <core/factories/logger-factory.h>
#include <core/loggers/ini-logger.h>
#include <core/loggers/raw-logger.h>

using namespace Enum;
using namespace Factory;

std::unique_ptr<Interface::ILogger> LoggerFactory::create(const Enum::LoggerType &type) {
	switch (type) {
		case LoggerType::IniLogger:
			return std::make_unique<Logger::IniLogger>();

		case LoggerType::RawLogger:
			return std::make_unique<Logger::RawLogger>();
	}

	return nullptr;
}
