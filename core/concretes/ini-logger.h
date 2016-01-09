#pragma once

#include <core/interfaces/ilogger.h>

#include <QSettings>
#include <chrono>

namespace Concrete {

	class IniLogger final : public Interface::ILogger {
	public:
		explicit IniLogger();
		virtual ~IniLogger() = default;

		virtual void init(Interface::ITestCase *) override;
		virtual void done(Interface::ITestCase *) override;

	private:
		QSettings m_file;
		std::chrono::time_point<std::chrono::system_clock> m_begin;
		std::chrono::time_point<std::chrono::system_clock> m_end;

	};

}
