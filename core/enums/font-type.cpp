#include <core/enums/font-type.h>

using namespace Enum;

QFont Enum::paper(const FontType &type) {
	QFont font;

	switch (type) {
		case FontType::Title:
			font.setBold(true);
			font.setPointSize(28);
			break;

		case FontType::Subtitle:
			font.setBold(true);
			font.setPointSize(18);
			break;

		case FontType::XAxis:
			font.setBold(false);
			font.setPointSize(16);
			break;

		case FontType::YAxis:
			font.setBold(true);
			font.setPointSize(16);
			break;

		case FontType::Legend:
			font.setBold(true);
			font.setPointSize(20);
			break;
	}

	return font;
}

QFont Enum::factory(const FontType &type) {
	QFont font;

	switch (type) {
		case FontType::Title:
			font.setBold(true);
			font.setPointSize(19);
			break;

		case FontType::Subtitle:
			font.setBold(true);
			font.setPointSize(9);
			break;

		case FontType::XAxis:
			font.setBold(false);
			font.setPointSize(8);
			break;

		case FontType::YAxis:
			font.setBold(true);
			font.setPointSize(8);
			break;

		case FontType::Legend:
			font.setBold(true);
			font.setPointSize(10);
			break;
	}

	return font;
}
