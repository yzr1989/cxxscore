#pragma once

#include <core/enums/logger-type.h>

namespace Interface {

class ITestCase;

class ILogger {
public:
	explicit ILogger() = default;
	virtual ~ILogger() = default;

	virtual Enum::LoggerType type() const = 0;

	virtual void init(ITestCase *) = 0;
	virtual void done(ITestCase *, double duration, const uint64_t ips) = 0;
};
}
