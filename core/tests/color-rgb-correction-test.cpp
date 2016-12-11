#include <core/tests/color-rgb-correction-test.h>

using namespace Test;

Enum::TestType ColorRGBCorrectionTest::type() const { return Enum::TestType::ColorRGBCorrection; }

u64 ColorRGBCorrectionTest::execute(u64 in)
{
	auto r = static_cast<uint32_t>((in >> 0x10) & 0xffu);
	auto g = static_cast<uint32_t>((in >> 0x08) & 0xffu);
	auto b = static_cast<uint32_t>((in >> 0x00) & 0xffu);
	r *= (in % 10) + 1;
	g *= (in % 20) + 1;
	b *= (in % 30) + 1;
	r = std::min(0xffu, r);
	g = std::min(0xffu, g);
	b = std::min(0xffu, b);
	u64 color = 0;
	color |= r << 0x10;
	color |= g << 0x08;
	color |= b << 0x00;
	return color;
}
