#pragma once

#include <core/managers/file-manager.h>

#include <QTabWidget>
#include <QMap>

namespace Widget {

	class Plot;

	class PlotTab : public QTabWidget {
	public:
		explicit PlotTab(QWidget *parent = nullptr);
		virtual ~PlotTab() = default;

		Plot *insert(const QString &name);

		void saveAllPlots(Manager::FileManager &manager);

	private:
		QMap<QString, Plot *> m_table;
	};

}
