#pragma once

#include <core/enums/test-type.h>

namespace Interface {

class ITestCase {
public:
	explicit ITestCase() = default;
	virtual ~ITestCase() = default;

	virtual Enum::TestType type() const = 0;
	virtual u64 execute(u64 in) = 0;
};
}
