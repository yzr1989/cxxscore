#include <core/platforms/linux-platform.h>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <sched.h>
#include <unistd.h>

using namespace Platform;

LinuxPlatform::LinuxPlatform() {
	QFile file("/proc/sys/vm/drop_caches");

	if (!file.open(QIODevice::ReadWrite))
		return;

	QTextStream stream(&file);
	stream << "3";
	struct sched_param param;
	param.__sched_priority = 99;
	sched_setscheduler(getpid(), SCHED_RR, &param);
}

Enum::PlatformType LinuxPlatform::type() const {
	return Enum::PlatformType::Linux;
}
