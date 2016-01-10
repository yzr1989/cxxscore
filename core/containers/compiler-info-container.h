#pragma once

#include <core/abstracts/abstract-container.h>
#include <QString>

namespace Container {

	class CompilerInfoContainer final : public Abstract::AbstractContainer {
	public:
		explicit CompilerInfoContainer() = default;
		virtual ~CompilerInfoContainer() = default;

		virtual Enum::ContainerType type() const override;
		virtual Core::DataStream &operator << (Core::DataStream &in) override;
		virtual Core::DataStream &operator >> (Core::DataStream &out) const override;

		QString flags() const;
		QString name() const;

		void setFlags(const QString &flags);
		void setName(const QString &name);

	private:
		QString m_name;
		QString m_flags;

	};

}
