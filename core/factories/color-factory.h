#pragma once

#include <QColor>

namespace Factory {

	class ColorFactory {
	public:
		explicit ColorFactory() = delete;
		virtual ~ColorFactory() = delete;

		static QColor color(int i, int darker = 125, int alpha = 255);
	};
}
