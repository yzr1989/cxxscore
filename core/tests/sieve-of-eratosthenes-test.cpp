#include <core/tests/sieve-of-eratosthenes-test.h>
#include <algorithm>
#include <limits>

using namespace Test;
using namespace Enum;

TestType SieveOfEratosthenesTest::type() const { return TestType::SieveOfEratosthenes; }

uint64_t SieveOfEratosthenesTest::execute(uint64_t in) {
	constexpr auto size = 65536u;
	std::vector<bool> isPrimeNumber;
	isPrimeNumber.resize(size);

	std::fill(isPrimeNumber.begin(), isPrimeNumber.end(), true);

	for (auto i = 2u; i * i < size; i++)
		if (isPrimeNumber.at(i))
			for (auto j = 2u; i * j < size; j++) isPrimeNumber[i * j] = 0;

	return isPrimeNumber[in % size];
}
