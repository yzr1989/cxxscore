#pragma once

#include <core/interfaces/ilogger.h>
#include <core/functionals/container-writer.h>

namespace Logger {

class RawLogger final : public Interface::ILogger {
public:
	explicit RawLogger(const std::string &name);
	virtual ~RawLogger() = default;

	virtual Enum::LoggerType type() const override;

	virtual void init(Interface::ITestCase *) override;
	virtual void done(Interface::ITestCase *, double duration, const u64 ips) override;

private:
	Functional::ContainerWritter m_file;
};
}
