#pragma once

#include <core/enums/test-case-id-enum.h>

#include <string>

namespace Interface {

	class ITestCase {
	public:
		explicit ITestCase() = default;
		virtual ~ITestCase() = default;

		virtual Enum::TestCaseId id() const = 0;
		virtual std::string name() const = 0;
		virtual int execute() = 0;
		virtual int count() const = 0;
	};

}
