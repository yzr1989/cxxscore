#include <gui/window/main-window.h>
#include <ui_main-window.h>
#include <core/functionals/container-file.h>
#include <core/containers/test-result-container.h>
#include <core/containers/compiler-info-container.h>
#include <core/containers/platform-info-container.h>

#include <gui/widgets/plot.h>
#include <QtDebug>

using namespace Window;

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)

{
	ui->setupUi(this);
	setWindowTitle("Compiler performance platform: graph generator");
	loadFromFile("/home/dev/linux-x86_64-gcc-cpp.raw");
	loadFromFile("/home/dev/linux-x86_64-clang-cpp.raw");
	loadFromFile("/home/dev/linux-arm-gcc-cpp.raw");
	loadFromFile("/home/dev/linux-arm-clang-cpp.raw");
}

MainWindow::~MainWindow() {
	delete ui;
}

//boisko :)
void MainWindow::loadFromFile(const QString &fileName) {
	Functional::ContainerFile file(fileName);
	Container::PlatformInfoContainer platformInfo;
	Container::CompilerInfoContainer compilerInfo;

	do {
		auto container = file.read();

		if (container == nullptr)
			break;

		if (container->type() == Enum::ContainerType::CompilerInfo)
			compilerInfo = *static_cast<Container::CompilerInfoContainer *>(container.get());

		if (container->type() == Enum::ContainerType::PlatformInfo)
			platformInfo = *static_cast<Container::PlatformInfoContainer *>(container.get());

		if (container->type() != Enum::ContainerType::TestResult)
			continue;

		QVector <QColor> fg = {
			QColor(150, 222, 0),
			QColor(1, 92, 191),
			QColor(255, 131, 0),
			QColor(0, 222, 189)
		};
		QVector<QColor> bg = {
			QColor(150, 222, 0, 200),
			QColor(1, 92, 191, 200),
			QColor(255, 131, 0, 200),
			QColor(0, 222, 189, 200)
		};
		// stack bars ontop of each other:qChecksum(hash.data(), hash.size()
		Container::TestResultContainer *result = static_cast<Container::TestResultContainer *>(container.get());
		Widget::Plot *plot = ui->tabWidget->insert(result->name());
		plot->title()->setText("Przypadek testowy: \"" + result->name() + "\" x  " + QString::number(result->count()) + "");
		plot->subtitle()->setFont(QFont());
		plot->subtitle()->setText("CXXFLAGS: " + compilerInfo.flags());
		plot->subtitle()->setTextColor(Qt::darkGray);
		QString barName = (platformInfo.arch() + "/" + compilerInfo.name().toUpper());
		QPen pen;
		pen.setWidthF(2);
		QCPBars *bar = plot->bars(barName);
		bar->setName(barName + " (" + QString::number(result->duration(), 'f', 4) + "s)");
		QByteArray hash = barName.toUtf8();
		qDebug() << qChecksum(hash.data(), hash.size());
		QVector<double> ticks = plot->yAxis->tickVector();
		QVector<QString> labels = plot->yAxis->tickVectorLabels();
		double id = 0;

		if (!ticks.isEmpty())
			id = ticks.last() + 1;

		pen.setBrush(fg.at(static_cast<int>(id) % fg.size()).darker(125));
		bar->setPen(pen);
		bar->setBrush(bg.at(static_cast<int>(id) % bg.size()).darker(125));
		ticks << id;
		labels << barName;
		plot->yAxis->setTickVector(ticks);
		plot->yAxis->setTickVectorLabels(labels);
		plot->yAxis->setTickLength(0, 4);
		plot->yAxis->grid()->setVisible(true);
		plot->yAxis->setRange(-1, ticks.length());
		// prepare y axis:

		if (plot->xAxis->range().upper < result->duration() + 1)
			plot->xAxis->setRange(0, result->duration() + 1);

		plot->xAxis->setPadding(5); // a bit more space to the left border
		plot->xAxis->setLabel("Czas (s)");
		plot->xAxis->grid()->setSubGridVisible(true);
		//customPlot->xAxis->setLabel(compilerInfo.flags());
		QPen gridPen;
		gridPen.setStyle(Qt::SolidLine);
		gridPen.setColor(QColor(0, 0, 0, 25));
		plot->xAxis->grid()->setPen(gridPen);
		gridPen.setStyle(Qt::DotLine);
		plot->xAxis->grid()->setSubGridPen(gridPen);
		plot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
		// Add data:
		QVector<double> data;
		data.resize(ticks.length());
		data.fill(0);
		data[id] = result->duration();
		bar->setData(ticks, data);
	} while (true);
}
