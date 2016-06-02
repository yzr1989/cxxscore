#pragma once

#include <core/enums/test-type.h>

#include <QString>

namespace Interface {

class ITestCase {
public:
	explicit ITestCase() = default;
	virtual ~ITestCase() = default;

	virtual Enum::TestType type() const = 0;
	virtual uint64_t execute(uint64_t in) = 0;
	virtual uint64_t count() const = 0;
};
}
