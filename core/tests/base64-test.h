#pragma once

#include <core/abstracts/abstract-test-case.h>

namespace Test {

class Base64Test final : public Abstract::AbstractTestCase {
public:
	explicit Base64Test() = default;
	virtual ~Base64Test() = default;

	virtual Enum::TestType type() const override;
	virtual uint64_t execute(uint64_t in) override;
};
}
