#pragma once

#include <core/abstracts/abstract-container.h>
#include <core/enums/test-type.h>
#include <QString>

namespace Container {

class TestCaseInfoContainer final : public Abstract::AbstractContainer {
public:
	explicit TestCaseInfoContainer() = default;
	virtual ~TestCaseInfoContainer() = default;

	virtual Enum::ContainerType type() const override;
	virtual Core::DataStream &operator<<(Core::DataStream &in) override;
	virtual Core::DataStream &operator>>(Core::DataStream &out) const override;

	Enum::TestType id() const;
	quint64 count() const;
	double duration() const;

	void setCount(const quint64 &count);
	void setDuration(double duration);
	void setId(const Enum::TestType &id);

private:
	Enum::TestType m_id;
	double m_duration;
	quint64 m_count;
};
}
