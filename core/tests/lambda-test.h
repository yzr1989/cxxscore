#pragma once

#include <core/abstracts/abstract-test-case.h>

namespace Test {

class LambdaTest final : public Abstract::AbstractTestCase {
public:
	explicit LambdaTest() = default;
	virtual ~LambdaTest() = default;

	virtual Enum::TestType type() const override;
	virtual u64 execute(u64 in) override;
};
}
