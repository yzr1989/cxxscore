#pragma once

#include <string>

namespace Interface {

	class ITestCase {
	public:
		explicit ITestCase() = default;
		virtual ~ITestCase() = default;

		virtual std::string name() const = 0;
		virtual int execute() = 0;
		virtual int count() const = 0;
	};

}
