#include <core/tests/color-brightness-correction-test.h>

using namespace Test;

Enum::TestType ColorBrightnessCorrectionTest::type() const { return Enum::TestType::ColorBrightnessCorrection; }

uint64_t ColorBrightnessCorrectionTest::execute(uint64_t in) {
	auto r = static_cast<uint32_t>((in >> 0x10) & 0xffu);
	auto g = static_cast<uint32_t>((in >> 0x08) & 0xffu);
	auto b = static_cast<uint32_t>((in >> 0x00) & 0xffu);
	const double brightness = (in % 10) + 1;
	r *= brightness;
	g *= brightness;
	b *= brightness;
	r = std::min(0xffu, r);
	g = std::min(0xffu, g);
	b = std::min(0xffu, b);
	uint64_t color = 0;
	color |= r << 0x10;
	color |= g << 0x08;
	color |= b << 0x00;
	return color;
}
