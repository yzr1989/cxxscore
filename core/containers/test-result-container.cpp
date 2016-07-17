#include <core/containers/test-result-container.h>

using namespace Container;

Enum::ContainerType TestCaseInfoContainer::type() const {
	return Enum::ContainerType::TestCaseInfo;
}

Core::DataStream &TestCaseInfoContainer::operator<<(Core::DataStream &in) {
	in >> m_duration;
	in >> m_count;
	in.readRawData(reinterpret_cast<char *>(&m_id), sizeof(m_id));
	in.readRawData(reinterpret_cast<char *>(&m_ips), sizeof(m_ips));
	return in;
}

Core::DataStream &TestCaseInfoContainer::operator>>(Core::DataStream &out) const {
	out << m_duration;
	out << m_count;
	out.writeRawData(reinterpret_cast<const char *>(&m_id), sizeof(m_id));
	out.writeRawData(reinterpret_cast<const char *>(&m_ips), sizeof(m_ips));
	return out;
}

double TestCaseInfoContainer::duration() const {
	return m_duration;
}

uint64_t TestCaseInfoContainer::ips() const
{
	return m_ips;
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

void TestCaseInfoContainer::setIps(const uint64_t ips)
{
	m_ips = ips;
}

quint64 TestCaseInfoContainer::count() const {
	return m_count;
}

void TestCaseInfoContainer::setCount(const quint64 &count) {
	m_count = count;
}
