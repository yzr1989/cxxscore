#include <core/factories/color-factory.h>

#include <vector>

using namespace Factory;

QColor ColorFactory::color(int i, int darker, int alpha) {
	std::vector<QColor> colors = {
		QColor(150, 222, 0, alpha),
		QColor(1, 92, 191, alpha),
		QColor(255, 131, 0, alpha),
		QColor(0, 222, 189, alpha),
		QColor(0xde, 0x9c, 0x9c, alpha),
		QColor(0xa4, 0x7e, 0xd3, alpha)};
	return colors.at(i % colors.size()).darker(darker);
}
