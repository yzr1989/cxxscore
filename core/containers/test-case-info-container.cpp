#include <core/containers/test-case-info-container.h>

using namespace Container;

Enum::ContainerType Container::TestCaseContainer::type() const {
	return Enum::ContainerType::TestCase;
}

Core::DataStream &TestCaseContainer::operator <<(Core::DataStream &in) {
	m_compiler << in;
	m_platform << in;
	m_testcase << in;
	return in;
}

Core::DataStream &TestCaseContainer::operator >>(Core::DataStream &out) const {
	m_compiler >> out;
	m_platform >> out;
	m_testcase >> out;
	return out;
}

CompilerInfoContainer &TestCaseContainer::compiler() {
	return m_compiler;
}

PlatformInfoContainer &TestCaseContainer::platform() {
	return m_platform;
}

TestCaseInfoContainer &TestCaseContainer::testcase() {
	return m_testcase;
}

const CompilerInfoContainer &TestCaseContainer::constCompiler() const {
	return m_compiler;
}

const PlatformInfoContainer &TestCaseContainer::constPlatform() const {
	return m_platform;
}

const TestCaseInfoContainer &TestCaseContainer::constTestcase() const {
	return m_testcase;
}
