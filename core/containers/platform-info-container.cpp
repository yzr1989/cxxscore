#include <core/containers/platform-info-container.h>

using namespace Container;

Enum::ContainerType PlatformInfoContainer::type() const {
	return Enum::ContainerType::PlatformInfo;
}

Core::DataStream &PlatformInfoContainer::operator <<(Core::DataStream &in) {
	m_arch = in.readThrivedUtf8String();
	m_name = in.readThrivedUtf8String();
	return in;
}

Core::DataStream &PlatformInfoContainer::operator >>(Core::DataStream &out) const {
	out.writeThrivedUtf8String(m_arch);
	out.writeThrivedUtf8String(m_name);
	return out;
}

QString PlatformInfoContainer::name() const {
	return m_name;
}

void PlatformInfoContainer::setName(const QString &name) {
	m_name = name;
}

QString PlatformInfoContainer::arch() const {
	return m_arch;
}

void PlatformInfoContainer::setArch(const QString &architecture) {
	m_arch = architecture;
}
