#pragma once

#include <core/abstracts/abstract-test-case.h>

namespace Test {

class EmptyCallTest final : public Abstract::AbstractTestCase {
public:
	explicit EmptyCallTest() = default;
	virtual ~EmptyCallTest() = default;

	virtual Enum::TestType type() const override;
	virtual u64 execute(u64 in) override;
};
}
