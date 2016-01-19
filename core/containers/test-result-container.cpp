#include <core/containers/test-result-container.h>

using namespace Container;

Enum::ContainerType TestCaseInfoContainer::type() const {
	return Enum::ContainerType::TestCaseInfo;
}

Core::DataStream &TestCaseInfoContainer::operator <<(Core::DataStream &in) {
	m_name = in.readThrivedUtf8String();
	m_description = in.readThrivedUtf8String();
	in >> m_duration;
	in >> m_count;
	return in;
}

Core::DataStream &TestCaseInfoContainer::operator >>(Core::DataStream &out) const {
	out.writeThrivedUtf8String(m_name);
	out.writeThrivedUtf8String(m_description);
	out << m_duration;
	out << m_count;
	return out;
}

double TestCaseInfoContainer::duration() const {
	return m_duration;
}

void TestCaseInfoContainer::setDuration(double duration) {
	m_duration = duration;
}

QString TestCaseInfoContainer::name() const {
	return m_name;
}

void TestCaseInfoContainer::setName(const QString &name) {
	m_name = name;
}

QString TestCaseInfoContainer::description() const {
	return m_description;
}

void TestCaseInfoContainer::setDescription(const QString &description) {
	m_description = description;
}

quint64 TestCaseInfoContainer::count() const {
	return m_count;
}

void TestCaseInfoContainer::setCount(const quint64 &count) {
	m_count = count;
}
