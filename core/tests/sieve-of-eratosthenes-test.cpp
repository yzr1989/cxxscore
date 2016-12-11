#include <core/tests/sieve-of-eratosthenes-test.h>
#include <algorithm>
#include <limits>
#include <array>

using namespace Test;
using namespace Enum;

TestType SieveOfEratosthenesTest::type() const { return TestType::SieveOfEratosthenes; }

u64 SieveOfEratosthenesTest::execute(u64 in) {
	constexpr auto size = 65536u;
	std::array<bool, size> isPrimeNumber;
	//isPrimeNumber.resize(size);

	std::fill(std::begin(isPrimeNumber), std::end(isPrimeNumber), true);

	for (auto i = 2u; i * i < size; i++)
		if (isPrimeNumber.at(i))
			for (auto j = 2u; i * j < size; j++) isPrimeNumber[i * j] = 0;

	return isPrimeNumber[in % size];
}
