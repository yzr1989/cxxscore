#include <core/containers/compiler-info-container.h>
#include <core/containers/platform-info-container.h>
#include <core/containers/test-result-container.h>
#include <core/factories/color-factory.h>
#include <core/functionals/container-reader.h>
#include <gui/widgets/plot.h>
#include <gui/window/main-window.h>
#include <QtDebug>
#include <ui_main-window.h>

using namespace Window;

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)

{
	ui->setupUi(this);
	setWindowTitle("Compiler performance platform: graph generator");
	loadFromFile("/home/dev/linux-x86_64-gcc-4.9.3-cpp.raw");
	loadFromFile("/home/dev/linux-x86_64-gcc-5.3.0-cpp.raw");
	loadFromFile("/home/dev/linux-x86_64-clang-3.6.2-cpp.raw");
	//loadFromFile("/home/dev/linux-arm-gcc-cpp.raw");
	//loadFromFile("/home/dev/linux-arm-clang-cpp.raw");
}

MainWindow::~MainWindow() {
	delete ui;
}

//boisko :)
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
		QString name = prettyname(result->testcase().id());
		Widget::Plot *plot = ui->tabWidget->insert(name);
		plot->title()->setText("Przypadek testowy: \"" + name + "\" x  " + QString::number(result->testcase().count()) + "");
		//plot->subtitle()->setFont(QFont());
		plot->subtitle()->setText("CXXFLAGS: ");
		plot->subtitle()->setTextColor(Qt::darkGray);
		plot->insert(*static_cast<Container::TestCaseContainer *>(container.get()));
	} while (true);
}
