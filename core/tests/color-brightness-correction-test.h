#pragma once

#include <core/abstracts/abstract-test-case.h>
#include <cstdint>

namespace Test {

class ColorBrightnessCorrectionTest final : public Abstract::AbstractTestCase {
public:
	explicit ColorBrightnessCorrectionTest() = default;
	virtual ~ColorBrightnessCorrectionTest() = default;

	virtual Enum::TestType type() const override;
	virtual uint64_t execute(uint64_t in) override;
};
}
