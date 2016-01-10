#pragma once

#include <core/abstracts/abstract-container.h>
#include <QString>

namespace Container {

	class PlatformInfoContainer final : public Abstract::AbstractContainer {
	public:
		explicit PlatformInfoContainer() = default;
		virtual ~PlatformInfoContainer() = default;

		virtual Enum::ContainerType type() const override;
		virtual Core::DataStream &operator << (Core::DataStream &in) override;
		virtual Core::DataStream &operator >> (Core::DataStream &out) const override;

		QString arch() const;
		QString name() const;

		void setArch(const QString &architecture);
		void setName(const QString &name);

	private:
		QString m_name;
		QString m_arch;

	};

}
