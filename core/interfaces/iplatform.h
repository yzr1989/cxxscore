#pragma once

#include <core/enums/platform-type.h>
#include <core/interfaces/templates/itemplate-attach.h>
#include "core/types.h"

namespace Interface {

class ITestCase;
class ILogger;

class IPlatform
	: public Template::IAttachTemplate<Interface::ITestCase>,
	  public Template::IAttachTemplate<Interface::ILogger> {
public:
	using Template::IAttachTemplate<Interface::ITestCase>::attach;
	using Template::IAttachTemplate<Interface::ILogger>::attach;

	explicit IPlatform() = default;
	virtual ~IPlatform() = default;

	virtual Enum::PlatformType type() const = 0;
	virtual void run(volatile int count) = 0;

protected:
	virtual void init(Interface::ITestCase *test) = 0;
	virtual u64 exec(Interface::ITestCase *test) = 0;
	virtual void done(Interface::ITestCase *test, const double duration, const u64 ir) = 0;
};
}
