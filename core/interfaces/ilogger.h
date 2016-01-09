#pragma once

namespace Interface {

	class ITestCase;

	class ILogger {
	public:
		explicit ILogger() = default;
		virtual ~ILogger() = default;

		virtual void init(ITestCase *) = 0;
		virtual void done(ITestCase *) = 0;

	};

}
