#pragma once

#include <core/interfaces/ilogger.h>
#include <core/functionals/container-file.h>

namespace Logger {

	class RawLogger final : public Interface::ILogger {
	public:
		explicit RawLogger(const QString &name);
		virtual ~RawLogger() = default;

		virtual Enum::LoggerType type() const override;

		virtual void init(Interface::ITestCase *) override;
		virtual void done(Interface::ITestCase *, double duration) override;

	private:
		Functional::ContainerFile m_file;

	};

}
