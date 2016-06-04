#pragma once

#include <core/abstracts/abstract-test-case.h>

namespace Test {

class LambdaTest final : public Abstract::AbstractTestCase {
public:
	explicit LambdaTest() = default;
	virtual ~LambdaTest() = default;

	virtual Enum::TestType type() const override;
	virtual uint64_t execute(uint64_t in) override;
};
}
