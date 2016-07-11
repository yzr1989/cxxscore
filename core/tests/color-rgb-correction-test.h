#pragma once

#include <core/abstracts/abstract-test-case.h>

namespace Test {

class ColorRGBCorrectionTest final : public Abstract::AbstractTestCase {
public:
	explicit ColorRGBCorrectionTest() = default;
	virtual ~ColorRGBCorrectionTest() = default;

	virtual Enum::TestType type() const override;
	virtual uint64_t execute(uint64_t in) override;
};
}
