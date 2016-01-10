#include <core/containers/test-result-container.h>

using namespace Container;

Enum::ContainerType TestResultContainer::type() const {
	return Enum::ContainerType::TestResult;
}

Core::DataStream &TestResultContainer::operator <<(Core::DataStream &in) {
	m_name = in.readThrivedUtf8String();
	m_description = in.readThrivedUtf8String();
	in >> m_duration;
	in >> m_count;
	return in;
}

Core::DataStream &TestResultContainer::operator >>(Core::DataStream &out) const {
	out.writeThrivedUtf8String(m_name);
	out.writeThrivedUtf8String(m_description);
	out << m_duration;
	out << m_count;
	return out;
}

double TestResultContainer::duration() const {
	return m_duration;
}

void TestResultContainer::setDuration(double duration) {
	m_duration = duration;
}

QString TestResultContainer::name() const {
	return m_name;
}

void TestResultContainer::setName(const QString &name) {
	m_name = name;
}

QString TestResultContainer::description() const {
	return m_description;
}

void TestResultContainer::setDescription(const QString &description) {
	m_description = description;
}

quint64 TestResultContainer::count() const {
	return m_count;
}

void TestResultContainer::setCount(const quint64 &count) {
	m_count = count;
}
