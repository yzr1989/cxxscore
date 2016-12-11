#pragma once

#include <core/abstracts/abstract-test-case.h>

namespace Test {

class SieveOfEratosthenesTest final : public Abstract::AbstractTestCase {
public:
	explicit SieveOfEratosthenesTest() = default;
	virtual ~SieveOfEratosthenesTest() = default;

	virtual Enum::TestType type() const override;
	virtual u64 execute(u64 in) override;
};
}
