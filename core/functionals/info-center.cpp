#include <core/functionals/info-center.h>
#include <iostream>

using namespace Functional;
using namespace Enum;

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

void InfoCenter::populate(Container::CompilerInfoContainer &container) {
#ifdef __clang__
	container.setId(Enum::CompilerType::Clang);
	container.version().setMajor(__clang_major__);
	container.version().setMinor(__clang_minor__);
	container.version().setPatch(__clang_patchlevel__);
#else
	container.setId(Enum::CompilerType::Gcc);
	container.version().setMajor(__GNUC__);
	container.version().setMinor(__GNUC_MINOR__);
	container.version().setPatch(__GNUC_PATCHLEVEL__);
#endif
	container.setFlags(TOSTRING(CXXFLAGS));
}

void InfoCenter::populate(Container::PlatformInfoContainer &container) {
#ifdef __i386__
	container.setArch(ArchitectureType::x86);
#endif
#ifdef __x86_64__
	container.setArch(ArchitectureType::x86_64);
#endif
#ifdef __arm__
	container.setArch(ArchitectureType::ARM);
#endif
#ifdef __unix__
	container.setPlatform(PlatformType::Linux);
#endif
}

void InfoCenter::print(Container::CompilerInfoContainer &container) {
	std::cout << "Compiler info:" << std::endl;
	std::cout << "\tcompiler: " << name(container.id()).toStdString() << std::endl;
	std::cout << "\tversion: " << container.version().toString().toStdString() << std::endl;
	std::cout << "\tflags: " << container.flags().toStdString() << std::endl;
	std::cout << std::endl;
}

void InfoCenter::print(Container::PlatformInfoContainer &container) {
	std::cout << "Platform info:" << std::endl;
	std::cout << "\tplatform: " << name(container.platform()).toStdString() << std::endl;
	std::cout << "\tarchitecture: " << name(container.arch()).toStdString() << std::endl;
	std::cout << std::endl;
}
