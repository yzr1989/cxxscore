#include <core/containers/platform-info-container.h>

using namespace Container;

Enum::ContainerType PlatformInfoContainer::type() const {
	return Enum::ContainerType::PlatformInfo;
}

Core::DataStream &PlatformInfoContainer::operator <<(Core::DataStream &in) {
	in.readRawData(reinterpret_cast<char *>(&m_arch), sizeof(m_arch));
	in.readRawData(reinterpret_cast<char *>(&m_platform), sizeof(m_platform));
	return in;
}

Core::DataStream &PlatformInfoContainer::operator >>(Core::DataStream &out) const {
	out.writeRawData(reinterpret_cast<const char *>(&m_arch), sizeof(m_arch));
	out.writeRawData(reinterpret_cast<const char *>(&m_platform), sizeof(m_platform));
	return out;
}

Enum::ArchitectureType PlatformInfoContainer::arch() const {
	return m_arch;
}

void PlatformInfoContainer::setArch(const Enum::ArchitectureType &arch) {
	m_arch = arch;
}

Enum::PlatformType PlatformInfoContainer::platform() const {
	return m_platform;
}

void PlatformInfoContainer::setPlatform(const Enum::PlatformType &platform) {
	m_platform = platform;
}

