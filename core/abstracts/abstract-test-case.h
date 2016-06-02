#pragma once

#include <core/interfaces/itestcase.h>

namespace Abstract {

class AbstractTestCase : public Interface::ITestCase {
public:
	explicit AbstractTestCase() = default;
	virtual ~AbstractTestCase() = default;

	virtual uint64_t count() const;
};
}
