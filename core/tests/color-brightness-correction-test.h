#pragma once

#include <core/abstracts/abstract-test-case.h>
#include <cstdint>

namespace Test {

class ColorBrightnessCorrectionTest final : public Abstract::AbstractTestCase {
public:
	explicit ColorBrightnessCorrectionTest() = default;
	virtual ~ColorBrightnessCorrectionTest() = default;

	virtual Enum::TestType type() const override;
	virtual u64 execute(u64 in) override;
};
}
