#include <core/enums/test-type.h>

using namespace Enum;

std::string Enum::name(const TestType &type) {
	switch (type) {
		case TestType::Base64: return "Base64";
		case TestType::EmptyCall: return "EmptyCall";
		case TestType::NaiveFactorial: return "NaiveFactorial";
		case TestType::TailCallFactorial: return "TailCallFactorial";
		case TestType::MergeSort: return "MergeSort";
		case TestType::NaiveFibonacci: return "NaiveFibonacci";
		case TestType::NaiveNWD: return "NaiveNWD";
		case TestType::TailCallFibonacci: return "TailCallFibonacci";
		case TestType::Lambda: return "Lambda";
		case TestType::StringConcate: return "StringConcate";
		case TestType::SieveOfEratosthenes: return "SieveOfEratosthenes";
		case TestType::ColorBrightnessCorrection: return "ColorBrightnessCorrection";
		case TestType::ColorRGBCorrection: return "ColorRGBCorrection";
	}

	return {};
}

std::string Enum::title(const TestType &type) {
	switch (type) {
		case TestType::Base64: return "Kodowanie i dekodowanie Base64";
		case TestType::EmptyCall: return "Wykonywanie pustych funkcji, O(n)";
		case TestType::NaiveFactorial: return "Silnia, rekurencja, O(n)";
		case TestType::TailCallFactorial: return "Silnia, rekurencja ogonowa, O(n)";
		case TestType::MergeSort: return "Sortowanie przez scalanie, O(nlog(n))";
		case TestType::NaiveFibonacci: return "Ciąg fibonacciego, rekurencja, O(n^2)";
		case TestType::NaiveNWD: return "Naiwne NWD, O(n)";
		case TestType::TailCallFibonacci: return "Ciąg fibonacciego, rekurencja ogonowa, O(n)";
		case TestType::Lambda: return "Lambda";
		case TestType::StringConcate: return "Konkatenacja ciągu znaków";
		case TestType::SieveOfEratosthenes: return "Sito Eratostenesa";
		case TestType::ColorBrightnessCorrection: return "Korekcja koloru (jasność)";
		case TestType::ColorRGBCorrection: return "Korekcja koloru (rgb)";
	}

	return {};
}
