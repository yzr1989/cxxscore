#include <core/tests/string-concate-test.h>

using namespace Test;

Enum::TestType StringConcateTest::type() const { return Enum::TestType::StringConcate; }

u64 StringConcateTest::execute(u64 in) {

	if (m_concate.size() > 32768)
		m_concate = "";

	m_concate += std::to_string(in);
	m_concate += std::to_string(in);
	m_concate += std::to_string(in);
	m_concate += std::to_string(in);
	return m_concate.size();
}
