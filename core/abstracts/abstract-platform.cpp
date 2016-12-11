#include <core/abstracts/abstract-platform.h>
#include <core/interfaces/itestcase.h>
#include <core/interfaces/ilogger.h>

#include <iostream>
#include <limits>
#include <time.h>
#include <chrono>

using namespace Abstract;
using namespace Interface;

AbstractPlatform::AbstractPlatform() {
}

AbstractPlatform::~AbstractPlatform() {
}

void AbstractPlatform::attach(std::unique_ptr<ITestCase> &&object) {
	m_testCaseList.push_back(std::move(object));
}

void AbstractPlatform::attach(std::unique_ptr<ILogger> &&object) {
	m_loggerList.push_back(std::move(object));
}

void AbstractPlatform::init(Interface::ITestCase *test) {
	for (auto &logger : m_loggerList)
		logger->init(test);

	std::cout
		<< "Running '"
		<< name(test->type())
		<< "' "
		<< std::flush;
}

u64 AbstractPlatform::exec(Interface::ITestCase *test) {
	volatile u64 ir = 0;

	std::chrono::time_point<std::chrono::high_resolution_clock> begin = std::chrono::high_resolution_clock::now();
//	double ElapsedTime::stop() {
//	m_end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<double> elapsed_seconds = m_end - m_begin;
//	return elapsed_seconds.count();

	std::chrono::duration<double> timeout;
	do {
		test->execute(++ir);
		timeout = std::chrono::high_resolution_clock::now() - begin;

	} while(timeout.count() < 5);

	return ir;
}

void AbstractPlatform::done(Interface::ITestCase *test, const double duration, const u64 ir) {
	for (auto &logger : m_loggerList)
		logger->done(test, duration, ir);

	std::cout << "done. [" << duration << "sec]" << "[" << ir << "]" << std::endl;
}

void AbstractPlatform::run(volatile int count) {
	m_count = count;
	u64 ips = 0;

	for (auto &testCase : m_testCaseList) {
		ITestCase *pointer = testCase.get();
		init(pointer);
		m_elapsed.start();
		ips = exec(pointer);
		auto duration = m_elapsed.stop();
		std::cout << " <<" << ips << ">> ";
		ips /= duration;
		done(pointer, duration, ips);
	}
}
