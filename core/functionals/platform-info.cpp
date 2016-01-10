#include <core/functionals/platform-info.h>
#include <iostream>

using namespace Functional;

Container::PlatformInfoContainer PlatformInfo::info() {
	Container::PlatformInfoContainer container;
#ifdef __i386__
	container.setArch("x86");
#endif
#ifdef __x86_64__
	container.setArch("x86_64");
#endif
#ifdef __arm__
	container.setArch("arm");
#endif
#ifdef __unix__
	container.setName("Linux");
#endif
	return container;
}

void PlatformInfo::printInfo() {
	Container::PlatformInfoContainer info = PlatformInfo::info();
	std::cout << "Platform info:" << std::endl;
	std::cout << "\tsystem: " << info.name().toStdString() << std::endl;
	std::cout << "\tarchitecture: " << info.arch().toStdString() << std::endl;
	std::cout << std::endl;
}
