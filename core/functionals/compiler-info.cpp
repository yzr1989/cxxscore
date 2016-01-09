#include <core/functionals/compiler-info.h>

using namespace Functional;

std::string CompilerInfo::compiler() {
#ifdef __clang__
	return "clang";
#else
	return "gcc";
#endif
}

std::string CompilerInfo::arch() {
#ifdef __i386__
	return "x86";
#endif
#ifdef __x86_64__
	return "x86_64";
#endif
#ifdef __arm__
	return "arm";
#endif
}

std::string CompilerInfo::ident()
{
	return CompilerInfo::arch() + "/" + CompilerInfo::compiler();
}
