#pragma once

#include <QTabWidget>
#include <QMap>

namespace Widget {

	class Plot;

	class PlotTab : public QTabWidget {
	public:
		explicit PlotTab(QWidget *parent = nullptr);
		virtual ~PlotTab() = default;

		Plot *insert(const QString &name);

	private:
		QMap<QString, Plot *> m_table;
	};

}
