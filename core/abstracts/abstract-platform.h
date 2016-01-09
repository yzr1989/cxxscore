#pragma once

#include <core/interfaces/iplatform.h>
#include <list>

namespace Abstract {

	class AbstractPlatform : public Interface::IPlatform {
	public:
		explicit AbstractPlatform();
		virtual ~AbstractPlatform();

		virtual void attach(std::unique_ptr<Interface::ITestCase> &&object) override;
		virtual void attach(std::unique_ptr<Interface::ILogger> &&object) override;
		virtual void run() override;

	protected:
		virtual void initTestCase(Interface::ITestCase *test) override;
		virtual void executeTest(Interface::ITestCase *test) override;
		virtual void doneTestCase(Interface::ITestCase *test) override;

	private:
		std::list <std::unique_ptr<Interface::ITestCase>> m_testCaseList;
		std::unique_ptr<Interface::ILogger> m_logger;
	};

}
