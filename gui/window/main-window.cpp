#include <core/containers/compiler-info-container.h>
#include <core/containers/platform-info-container.h>
#include <core/containers/test-result-container.h>
#include <core/factories/color-factory.h>
#include <core/functionals/container-reader.h>
#include <gui/widgets/plot.h>
#include <gui/window/main-window.h>
#include <QtDebug>
#include <ui_main-window.h>
#include <QDir>
#include <QRect>

using namespace Window;

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)

{
	ui->setupUi(this);
	setWindowTitle("Compiler performance platform: graph generator");

	for (auto &file : m_manager.list(Enum::Folder::Data))
		loadFromFile(file.absoluteFilePath());

	ui->tabWidget->saveAllPlots(m_manager);
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::loadFromFile(const QString &fileName) {
	Functional::ContainerReader file(fileName);

	do {
		auto container = file.read();

		if (container == nullptr)
			return;

		if (container->type() != Enum::ContainerType::TestCase)
			continue;

		// stack bars ontop of each other:qChecksum(hash.data(), hash.size()
		Container::TestCaseContainer *result = static_cast<Container::TestCaseContainer *>(container.get());
		QString tabname = prettyname(result->testcase().id());
		Widget::Plot *plot = ui->tabWidget->insert(tabname);
		plot->title()->setText("Przypadek testowy: \"" + tabname  + "\" x  " + QString::number(result->testcase().count()) + "");
		//plot->subtitle()->setFont(QFont());
		plot->subtitle()->setText("Mniejszy czas wykonania = lepszy wynik");
		plot->subtitle()->setTextColor(Qt::darkGray);
		plot->insert(*static_cast<Container::TestCaseContainer *>(container.get()));
	} while (true);
}

