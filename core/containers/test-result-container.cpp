#include <core/containers/test-result-container.h>

using namespace Container;

Enum::ContainerType TestCaseInfoContainer::type() const {
	return Enum::ContainerType::TestCaseInfo;
}

Core::DataStream &TestCaseInfoContainer::operator <<(Core::DataStream &in) {
	in >> m_duration;
	in >> m_count;
	in.readRawData(reinterpret_cast<char *>(&m_id), sizeof(m_id));
	return in;
}

Core::DataStream &TestCaseInfoContainer::operator >>(Core::DataStream &out) const {
	out << m_duration;
	out << m_count;
	out.writeRawData(reinterpret_cast<const char *>(&m_id), sizeof(m_id));
	return out;
}

double TestCaseInfoContainer::duration() const {
	return m_duration;
}

void TestCaseInfoContainer::setDuration(double duration) {
	m_duration = duration;
}

Enum::TestType TestCaseInfoContainer::id() const {
	return m_id;
}

void TestCaseInfoContainer::setId(const Enum::TestType &id) {
	m_id = id;
}

quint64 TestCaseInfoContainer::count() const {
	return m_count;
}

void TestCaseInfoContainer::setCount(const quint64 &count) {
	m_count = count;
}
