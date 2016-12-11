#include <core/containers/version-info-container.h>

using namespace Container;

Enum::ContainerType VersionInfoContainer::type() const {
	return Enum::ContainerType::CompilerInfo;
}

Core::DataStream &VersionInfoContainer::operator<<(Core::DataStream &in) {
	in >> m_major;
	in >> m_minor;
	in >> m_patch;
	return in;
}

Core::DataStream &VersionInfoContainer::operator>>(Core::DataStream &out) const {
	out << m_major;
	out << m_minor;
	out << m_patch;
	return out;
}

u8 VersionInfoContainer::major() const {
	return m_major;
}

void VersionInfoContainer::setMajor(const u8 &major) {
	m_major = major;
}

u8 VersionInfoContainer::minor() const {
	return m_minor;
}

void VersionInfoContainer::setMinor(const u8 &minor) {
	m_minor = minor;
}

u8 VersionInfoContainer::patch() const {
	return m_patch;
}

void VersionInfoContainer::setPatch(const u8 &patch) {
	m_patch = patch;
}

std::string VersionInfoContainer::toString() const {
	return std::to_string(m_major) + "." +
		std::to_string(m_minor) + "." +
		std::to_string(m_patch);
}
