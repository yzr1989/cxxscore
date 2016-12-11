#include <core/containers/compiler-info-container.h>
#include <core/containers/platform-info-container.h>
#include <core/containers/test-result-container.h>
#include <core/enums/font-type.h>
#include <core/factories/color-factory.h>
#include <core/functionals/container-reader.h>
#include <gui/widgets/plot.h>
#include <gui/window/main-window.h>
#include <ui_main-window.h>

using namespace Window;

MainWindow::MainWindow(QWidget *parent)
		: QMainWindow(parent)
		, ui(new Ui::MainWindow)

{
	ui->setupUi(this);
	setWindowTitle("CPP: Graph generator");

	QDir dir = QDir::home();
	dir.cd("data");

	for (auto &file : dir.entryInfoList({"*.*"}, QDir::Files, QDir::Reversed | QDir::Name))
		loadFromFile(file.absoluteFilePath());

	generatePlots();
	savePlots();
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::insertTestCase(Container::TestCaseContainer *container) {
	QString tabname = QString::fromStdString(name(container->testcase().id()));
	Widget::Plot *plot = ui->tabWidget->insert(tabname);
	//plot->title()->setText("Przypadek testowy: \"" + tabname  + "\", " + QString::number(container->testcase().count()) + " iteracji");
	plot->title()->setText(QString::fromStdString(title(container->testcase().id())) + ", " +
		QString::number(container->testcase().count()) + " iteracji");
	plot->subtitle()->setText("Wiecej iteracji = wieksza wydajność");
	plot->subtitle()->setTextColor(Qt::darkGray);
	plot->insert(*container);
	m_plots.insert(plot);
}

void MainWindow::loadFromFile(const QString &fileName) {
	Functional::ContainerReader file(fileName.toStdString());

	do {
		auto container = file.read();

		if (container == nullptr)
			return;

		if (container->type() != Enum::ContainerType::TestCase)
			continue;

		insertTestCase(static_cast<Container::TestCaseContainer *>(container.get()));
	} while (true);
}

void MainWindow::generatePlots() {
	for (auto plot : m_plots)
		plot->generate();
}

void MainWindow::savePlots() {
	QDir dir = QDir::home();
	dir.mkdir("plot");
	dir.cd("plot");

	for (auto plot : m_plots)
		plot->saveToFile(dir.path() + QDir::separator() + plot->testName() + ".png");
}
