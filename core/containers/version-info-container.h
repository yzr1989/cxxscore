#pragma once

#include <core/abstracts/abstract-container.h>

namespace Container {

class VersionInfoContainer final : public Abstract::AbstractContainer {
public:
	explicit VersionInfoContainer() = default;
	virtual ~VersionInfoContainer() = default;

	virtual Enum::ContainerType type() const override;
	virtual Core::DataStream &operator<<(Core::DataStream &in) override;
	virtual Core::DataStream &operator>>(Core::DataStream &out) const override;

	quint8 major() const;
	quint8 minor() const;
	quint8 patch() const;

	void setMajor(const quint8 &major);
	void setMinor(const quint8 &minor);
	void setPatch(const quint8 &patch);

	QString toString() const;

private:
	quint8 m_major;
	quint8 m_minor;
	quint8 m_patch;
};
}
