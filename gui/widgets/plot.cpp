#include <gui/widgets/plot.h>
#include <core/factories/color-factory.h>

using namespace Widget;

Plot::Plot(QWidget *parent)
	: QCustomPlot(parent)

{
	m_title = new QCPPlotTitle(this);
	m_subtitle = new QCPPlotTitle(this);
	plotLayout()->insertRow(0);
	plotLayout()->insertRow(0);
	plotLayout()->addElement(0, 0, m_title);
	plotLayout()->addElement(1, 0, m_subtitle);
	reset();
	legend->setVisible(true);
	axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom | Qt::AlignRight);
	legend->setBrush(QColor(255, 255, 255, 200));
	QPen legendPen;
	legendPen.setColor(QColor(130, 130, 130, 200));
	legend->setBorderPen(legendPen);
	QFont legendFont = font();
	legendFont.setPointSize(12);
	legend->setFont(legendFont);
	//setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
	xAxis->setRange(0, 0.01);
	setGrid();
}

Plot::~Plot() {
}

void Plot::insert(Container::TestCaseContainer &test) {
	for (QCPBars *bar : m_testBars)
		removePlottable(bar);

	m_tests.push_back(test);
	QVector <double> ticks;
	QVector <QString> labels;

	for (size_t i = 0; i < m_tests.size(); ++i) {
		//const Container::CompilerInfoContainer &compiler = m_tests.at(i).compiler();
		const Container::PlatformInfoContainer &platform = m_tests.at(i).platform();
		//const Container::TestCaseInfoContainer &testcase = m_tests.at(i).testcase();
		const QString bar = QString("[%1] %2").arg(
		                      platform.arch(), name(m_tests.at(i).compiler().id()));
		//  QString barName = (m_tests.at(i).platform().arch() +
		//                     "/" + QString::fromStdString(name(m_tests.at(i).compiler().id())));
		ticks << i;
		labels << bar;
	}

	yAxis->setTickVector(ticks);
	yAxis->setTickVectorLabels(labels);
	yAxis->setRange(-1, m_tests.size());

	for (size_t i = 0; i < m_tests.size(); ++i) {
		const Container::CompilerInfoContainer &compiler = m_tests.at(i).compiler();
		const Container::PlatformInfoContainer &platform = m_tests.at(i).platform();
		const Container::TestCaseInfoContainer &testcase = m_tests.at(i).testcase();
		const QString compilerName = name(compiler.id());
		auto bar = new QCPBars(yAxis, xAxis);
		QString barName = platform.arch() + "/" + compilerName + " v"
		                  + QString::number(compiler.constVersion().major()) + "."
		                  + QString::number(compiler.constVersion().minor()) + "."
		                  + QString::number(compiler.constVersion().patch());
		QPen pen;
		pen.setWidthF(2);
		bar->setName(barName + " (" + QString::number(testcase.duration(), 'f', 4) + "s)");
		pen.setBrush(Factory::ColorFactory::color(static_cast<int>(i), 125, 255));
		bar->setPen(pen);
		bar->setBrush(Factory::ColorFactory::color(static_cast<int>(i), 125, 180));
		QVector<double> data;
		data.resize(ticks.length());
		data.fill(0);
		data[i] = testcase.duration();
		bar->setData(ticks, data);
		m_testBars.push_back(bar);

		if (xAxis->range().upper < testcase.duration())
			xAxis->setRange(0, testcase.duration() + (testcase.duration() * 0.01));
	}

	size_t i = m_testBars.size();

	do {
		addPlottable(m_testBars.at(--i));
	} while (i != 0);
}

QCPPlotTitle *Plot::title() {
	return m_title;
}

QCPPlotTitle *Plot::subtitle() {
	return m_subtitle;
}

QCPBars *Plot::bars(const QString &name) {
	QCPBars *ptr = m_bars.value(name, nullptr);

	if (ptr == nullptr) {
		ptr =  new QCPBars(yAxis, xAxis);
		addPlottable(ptr);
		m_bars[name] = ptr;
	}

	return ptr;
}

void Plot::setGrid() {
	xAxis->setPadding(5);
	xAxis->setLabel("Czas (s)");
	xAxis->grid()->setSubGridVisible(true);
	QPen gridPen;
	gridPen.setStyle(Qt::SolidLine);
	gridPen.setColor(QColor(0, 0, 0, 25));
	xAxis->grid()->setPen(gridPen);
	gridPen.setStyle(Qt::DotLine);
	xAxis->grid()->setSubGridPen(gridPen);
	xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
}

void Plot::reset() {
	yAxis->setAutoTicks(false);
	yAxis->setAutoTickLabels(false);
	yAxis->setTickVector({});
	yAxis->setTickVectorLabels({});
	yAxis->setTickLabelRotation(0);
	yAxis->setSubTickCount(0);
	yAxis->setTickLength(0, 4);
	yAxis->grid()->setVisible(true);
	yAxis->setRange(-1, 1);
}

