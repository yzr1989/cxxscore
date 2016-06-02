#pragma once

#include <core/abstracts/abstract-test-case.h>

namespace Test {

class NaiveNWDTest final : public Abstract::AbstractTestCase {
public:
	explicit NaiveNWDTest() = default;
	virtual ~NaiveNWDTest() = default;

	virtual Enum::TestType type() const override;
	virtual uint64_t execute(uint64_t in) override;
};
}
