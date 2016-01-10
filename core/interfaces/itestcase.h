#pragma once

#include <core/enums/test-type-enum.h>

#include <QString>

namespace Interface {

	class ITestCase {
	public:
		explicit ITestCase() = default;
		virtual ~ITestCase() = default;

		virtual Enum::TestType id() const = 0;
		virtual QString name() const = 0;
		virtual int execute() = 0;
		virtual unsigned long long count() const = 0;
	};

}
