#pragma once

#include <core/abstracts/abstract-test-case.h>

namespace Test {

class MergeSortTest final : public Abstract::AbstractTestCase {
public:
	explicit MergeSortTest() = default;
	virtual ~MergeSortTest() = default;

	virtual Enum::TestType type() const override;
	virtual u64 execute(u64 in) override;
};
}
