#include <core/containers/version-info-container.h>

using namespace Container;

Enum::ContainerType VersionInfoContainer::type() const {
	return Enum::ContainerType::CompilerInfo;
}

Core::DataStream &VersionInfoContainer::operator <<(Core::DataStream &in) {
	in >> m_major;
	in >> m_minor;
	in >> m_patch;
	return in;
}

Core::DataStream &VersionInfoContainer::operator >>(Core::DataStream &out) const {
	out << m_major;
	out << m_minor;
	out << m_patch;
	return out;
}

quint8 VersionInfoContainer::major() const {
	return m_major;
}

void VersionInfoContainer::setMajor(const quint8 &major) {
	m_major = major;
}

quint8 VersionInfoContainer::minor() const {
	return m_minor;
}

void VersionInfoContainer::setMinor(const quint8 &minor) {
	m_minor = minor;
}

quint8 VersionInfoContainer::patch() const {
	return m_patch;
}

void VersionInfoContainer::setPatch(const quint8 &patch) {
	m_patch = patch;
}

QString VersionInfoContainer::toString() const {
	return
	  QString::number(m_major) + "." +
	  QString::number(m_minor) + "." +
	  QString::number(m_patch);
}
