#pragma once

#include <QFont>

namespace Enum {

	enum class FontType : quint8 {
		Title,
		Subtitle,
		Legend,
		XAxis,
		YAxis
	};

	QFont factory(const FontType &type);
	QFont paper(const FontType &type);

}
