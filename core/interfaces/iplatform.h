#pragma once

#include <core/interfaces/templates/itemplate-attach.h>

namespace Interface {

	class ITestCase;
	class ILogger;

	class IPlatform
		: public Template::IAttachTemplate<Interface::ITestCase>
		, public Template::IAttachTemplate<Interface::ILogger> {
	public:
		explicit IPlatform() = default;
		virtual ~IPlatform() = default;

		virtual void run() = 0;

	protected:
		virtual void initTestCase(Interface::ITestCase *test) = 0;
		virtual void executeTest(Interface::ITestCase *test) = 0;
		virtual void doneTestCase(Interface::ITestCase *test) = 0;

	};

}
