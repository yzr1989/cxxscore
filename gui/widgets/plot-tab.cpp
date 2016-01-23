#include <gui/widgets/plot-tab.h>
#include <gui/widgets/plot.h>
#include <qcustomplot.h>

using namespace Widget;

PlotTab::PlotTab(QWidget *parent)
	: QTabWidget(parent) {
}

Plot *PlotTab::insert(const QString &name) {
	Plot *ptr = m_table.value(name, nullptr);

	if (ptr == nullptr) {
		ptr = new Plot(name, this);
		m_table[name] = ptr;
		addTab(ptr, name);
	}

	return ptr;
}

void Widget::PlotTab::saveAllPlots(Manager::FileManager &manager) {
	for (auto plot : m_table.values())
		plot->saveToFile(manager.path(Enum::Folder::Plot, plot->testName()));
}
