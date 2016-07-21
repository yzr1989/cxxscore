#include <core/functionals/elapsed-time.h>

using namespace Functional;

void ElapsedTime::start() {
	m_begin = std::chrono::high_resolution_clock::now();
}

double ElapsedTime::stop() {
	m_end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed_seconds = m_end - m_begin;
	return elapsed_seconds.count();
}
