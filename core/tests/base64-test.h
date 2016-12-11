#pragma once

#include <core/abstracts/abstract-test-case.h>

namespace Test {

class Base64Test final : public Abstract::AbstractTestCase {
public:
	explicit Base64Test() = default;
	virtual ~Base64Test() = default;

	virtual Enum::TestType type() const override;
	virtual u64 execute(u64 in) override;
};
}
