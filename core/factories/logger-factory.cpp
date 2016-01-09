#include <core/factories/logger-factory.h>
#include <core/loggers/ini-logger.h>

using namespace Enum;
using namespace Factory;

std::unique_ptr<Interface::ILogger> LoggerFactory::create(const Enum::LoggerType &type) {
	switch (type) {
		case LoggerType::IniLogger:
			return std::make_unique<Logger::IniLogger>();
	}

	return nullptr;
}
