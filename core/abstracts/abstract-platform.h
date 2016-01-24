#pragma once

#include <core/interfaces/iplatform.h>
#include <core/functionals/elapsed-time.h>
#include <list>

namespace Abstract {

	class AbstractPlatform : public Interface::IPlatform {
	public:
		explicit AbstractPlatform();
		virtual ~AbstractPlatform();

		virtual void attach(std::unique_ptr<Interface::ITestCase> &&object) override;
		virtual void attach(std::unique_ptr<Interface::ILogger> &&object) override;
		virtual void run(int count) override;

	protected:
		virtual void init(Interface::ITestCase *test) override;
		virtual void exec(Interface::ITestCase *test) override;
		virtual void done(Interface::ITestCase *test) override;

	private:
		std::list <std::unique_ptr<Interface::ILogger>> m_loggerList;
		std::list <std::unique_ptr<Interface::ITestCase>> m_testCaseList;
		Functional::ElapsedTime m_elapsed;
		int m_count;
	};

}
