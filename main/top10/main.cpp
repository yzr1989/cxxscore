#include <core/functionals/container-reader.h>
#include <core/managers/file-manager.h>
#include <core/containers/test-case-info-container.h>

using namespace Container;
using namespace Functional;
using namespace Manager;

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <array>

int main(int argc, char *argv[]) {
	static_cast<void>(argc);
	static_cast<void>(argv);
	FileManager manager;
	std::vector<std::unique_ptr<TestCaseContainer>> tests;
	tests.reserve(1024);

	for (auto &name : manager.list(Enum::Folder::Data)) {
		ContainerReader file(name.absoluteFilePath());

		do {
			auto container = file.read();

			if (container == nullptr)
				break;

			if (container->type() != Enum::ContainerType::TestCase)
				continue;

			tests.emplace_back(static_cast<TestCaseContainer *>(container.release()));
		} while (true);
	}

	sort(tests.begin(), tests.end(),
		[](const std::unique_ptr<TestCaseContainer> &a, const std::unique_ptr<TestCaseContainer> &b) {
			return a->testcase().duration() < b->testcase().duration();
		});
	std::array<double, 2> m_compilerDuration;
	m_compilerDuration.fill(0);

	for (const auto &test : tests) {
		const CompilerInfoContainer &compiler = test->compiler();
		//const PlatformInfoContainer &platform = test->platform();
		const TestCaseInfoContainer &testcase = test->testcase();
		m_compilerDuration[static_cast<size_t>(compiler.id())] += testcase.duration();
		//std::cout << (++i) << ". " << compiler.flags().toStdString() << std::endl;
	}

	std::cout << "gcc   : " << m_compilerDuration[0] << "s" << std::endl;
	std::cout << "clang : " << m_compilerDuration[1] << "s" << std::endl;
	return 0;
}
