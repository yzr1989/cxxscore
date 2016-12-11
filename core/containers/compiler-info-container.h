#pragma once

#include <core/containers/version-info-container.h>
#include <core/enums/compiler-type.h>

namespace Container {

class CompilerInfoContainer final : public Abstract::AbstractContainer {
public:
	explicit CompilerInfoContainer() = default;
	virtual ~CompilerInfoContainer() = default;

	virtual Enum::ContainerType type() const override;
	virtual Core::DataStream &operator<<(Core::DataStream &in) override;
	virtual Core::DataStream &operator>>(Core::DataStream &out) const override;

	Enum::CompilerType id() const;
	std::string flags() const;

	void setFlags(const std::string &flags);
	void setId(const Enum::CompilerType &id);

	auto version() -> VersionInfoContainer &;
	auto constVersion() const -> const VersionInfoContainer &;

	std::string checksum() const;

private:
	Enum::CompilerType m_id;
	Container::VersionInfoContainer m_version;
	std::string m_flags;
};
}
