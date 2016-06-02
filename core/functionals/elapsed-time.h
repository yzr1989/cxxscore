#pragma once

#include <chrono>

namespace Functional {

class ElapsedTime {
public:
	explicit ElapsedTime() = default;
	virtual ~ElapsedTime() = default;

	void start();
	double stop();

private:
	std::chrono::time_point<std::chrono::system_clock> m_begin;
	std::chrono::time_point<std::chrono::system_clock> m_end;
};
}
