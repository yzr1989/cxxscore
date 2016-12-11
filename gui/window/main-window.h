#pragma once

#include <core/managers/file-manager.h>

#include <set>
#include <QMainWindow>

namespace Container {
class TestCaseContainer;
}

namespace Widget {
class Plot;
}

namespace Window {

namespace Ui {
class MainWindow;
}

class MainWindow final : public QMainWindow {
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

protected:
	void insertTestCase(Container::TestCaseContainer *container);
	void loadFromFile(const QString &fileName);
	void generatePlots();
	void savePlots();

private:
	std::set<Widget::Plot *> m_plots;
	Ui::MainWindow *ui;
};
}
