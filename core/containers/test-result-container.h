#pragma once

#include <core/abstracts/abstract-container.h>
#include <QString>

namespace Container {

	class TestResultContainer final : public Abstract::AbstractContainer {
	public:
		explicit TestResultContainer() = default;
		virtual ~TestResultContainer() = default;

		virtual Enum::ContainerType type() const override;
		virtual Core::DataStream &operator << (Core::DataStream &in) override;
		virtual Core::DataStream &operator >> (Core::DataStream &out) const override;

		double duration() const;
		QString description() const;
		QString name() const;
		quint64 count() const;

		void setCount(const quint64 &count);
		void setDescription(const QString &description);
		void setDuration(double duration);
		void setName(const QString &name);

	private:
		QString m_name;
		QString m_description;
		double m_duration;
		quint64 m_count;
	};

}
