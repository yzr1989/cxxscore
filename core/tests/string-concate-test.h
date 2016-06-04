#pragma once

#include <core/abstracts/abstract-test-case.h>
#include <string>

namespace Test {

class StringConcateTest final : public Abstract::AbstractTestCase {
public:
	explicit StringConcateTest() = default;
	virtual ~StringConcateTest() = default;

	virtual Enum::TestType type() const override;
	virtual uint64_t execute(uint64_t in) override;

private:
	std::string m_concate;
};
}
