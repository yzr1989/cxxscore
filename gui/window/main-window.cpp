#include <gui/window/main-window.h>
#include <ui_main-window.h>
#include <qcustomplot.h>
#include <core/functionals/container-file.h>
#include <core/containers/test-result-container.h>

using namespace Window;

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow) {
	ui->setupUi(this);
	Functional::ContainerFile file("/home/dev/benchmark.raw");

	do {
		auto container = file.read();

		if (container == nullptr)
			return;

		if (container->type() != Enum::ContainerType::TestResult)
			continue;

		Container::TestResultContainer *result = static_cast<Container::TestResultContainer*>(container.get());

		QCustomPlot *customPlot = new QCustomPlot();
		ui->tabWidget->addTab(customPlot, result->name());


	} while (true);
}

MainWindow::~MainWindow() {
	delete ui;
}
