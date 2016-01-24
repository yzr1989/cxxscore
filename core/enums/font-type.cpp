#include <core/enums/font-type.h>

using namespace Enum;

QFont Enum::factory(const FontType &type) {
	QFont font;

	switch (type) {
		case FontType::Title:
			font.setBold(true);
			font.setPointSize(24);
			break;

		case FontType::Subtitle:
			font.setBold(true);
			font.setPointSize(14);
			break;

		case FontType::XAxis:
			font.setBold(false);
			font.setPointSize(10);
			break;

		case FontType::YAxis:
			font.setBold(true);
			font.setPointSize(10);
			break;

		case FontType::Legend:
			font.setBold(true);
			font.setPointSize(16);
			break;
	}

	return font;
}
