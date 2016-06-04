#include <core/tests/string-concate-test.h>

using namespace Test;

Enum::TestType StringConcateTest::type() const { return Enum::TestType::StringConcate; }

uint64_t StringConcateTest::execute(uint64_t in) {
	m_concate += std::to_string(in);
	m_concate += std::to_string(in);
	m_concate += std::to_string(in);
	m_concate += std::to_string(in);
	return m_concate.size();
}
