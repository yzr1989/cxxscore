#pragma once

#include <core/abstracts/abstract-container.h>
#include <core/enums/architecture-type.h>
#include <core/enums/platform-type.h>
#include <QString>

namespace Container {

	class PlatformInfoContainer final : public Abstract::AbstractContainer {
	public:
		explicit PlatformInfoContainer() = default;
		virtual ~PlatformInfoContainer() = default;

		virtual Enum::ContainerType type() const override;
		virtual Core::DataStream &operator << (Core::DataStream &in) override;
		virtual Core::DataStream &operator >> (Core::DataStream &out) const override;

		Enum::ArchitectureType arch() const;
		Enum::PlatformType platform() const;

		void setArch(const Enum::ArchitectureType &arch);
		void setPlatform(const Enum::PlatformType &platform);

	private:
		Enum::ArchitectureType m_arch;
		Enum::PlatformType m_platform;

	};

}
