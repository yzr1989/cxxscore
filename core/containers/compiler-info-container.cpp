#include <core/containers/compiler-info-container.h>

using namespace Container;

Enum::ContainerType CompilerInfoContainer::type() const {
	return Enum::ContainerType::CompilerInfo;
}

Core::DataStream &CompilerInfoContainer::operator <<(Core::DataStream &in) {
	m_name = in.readThrivedUtf8String();
	m_flags = in.readThrivedUtf8String();
	return in;
}

Core::DataStream &CompilerInfoContainer::operator >>(Core::DataStream &out) const {
	out.writeThrivedUtf8String(m_name);
	out.writeThrivedUtf8String(m_flags);
	return out;
}

QString CompilerInfoContainer::name() const {
	return m_name;
}

void CompilerInfoContainer::setName(const QString &name) {
	m_name = name;
}

QString CompilerInfoContainer::flags() const {
	return m_flags;
}

void CompilerInfoContainer::setFlags(const QString &flags) {
	m_flags = flags;
}
