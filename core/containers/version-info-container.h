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

	u8 major() const;
	u8 minor() const;
	u8 patch() const;

	void setMajor(const u8 &major);
	void setMinor(const u8 &minor);
	void setPatch(const u8 &patch);

	std::string toString() const;

private:
	u8 m_major;
	u8 m_minor;
	u8 m_patch;
};
}
