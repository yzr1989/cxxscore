#pragma once

#include <core/abstracts/abstract-container.h>
#include <core/enums/test-type.h>
#include "core/types.h"

namespace Container {

class TestCaseInfoContainer final : public Abstract::AbstractContainer {
public:
	explicit TestCaseInfoContainer() = default;
	virtual ~TestCaseInfoContainer() = default;

	virtual Enum::ContainerType type() const override;
	virtual Core::DataStream &operator<<(Core::DataStream &in) override;
	virtual Core::DataStream &operator>>(Core::DataStream &out) const override;

	Enum::TestType id() const;
	u64 count() const;
	double duration() const;
	u64 ips() const;

	void setCount(const u64 &count);
	void setDuration(double duration);
	void setId(const Enum::TestType &id);
	void setIps(const u64 ips);

private:
	Enum::TestType m_id;
	double m_duration;
	u64 m_count;
	u64 m_ips;
};
}
