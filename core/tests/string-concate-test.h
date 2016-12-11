#pragma once

#include <core/abstracts/abstract-test-case.h>
#include <string>

namespace Test {

class StringConcateTest final : public Abstract::AbstractTestCase {
public:
	explicit StringConcateTest() = default;
	virtual ~StringConcateTest() = default;

	virtual Enum::TestType type() const override;
	virtual u64 execute(u64 in) override;

private:
	std::string m_concate;
};
}
