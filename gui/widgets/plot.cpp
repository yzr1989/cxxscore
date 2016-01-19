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
	setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
	xAxis->setRange(0, 1);
	setGrid();
}

Plot::~Plot() {
}

void Plot::insert(Container::TestCaseContainer &test) {
	m_tests.push_back(test);
	QVector <double> ticks;
	QVector <QString> labels;

	for (size_t i = 0; i < m_tests.size(); ++i) {
		QString barName = (m_tests.at(i).platform().arch() +
		                   "/" + m_tests.at(i).compiler().name().toUpper());
		ticks << i;
		labels << barName;
	}

	yAxis->setTickVector(ticks);
	yAxis->setTickVectorLabels(labels);
	yAxis->setRange(-1, m_tests.size());

	for (size_t i = 0; i < m_tests.size(); ++i) {
		auto bar = new QCPBars(yAxis, xAxis);
		QString barName = (m_tests.at(i).platform().arch() +
		                   "/" + m_tests.at(i).compiler().name().toUpper());
		addPlottable(bar);
		QPen pen;
		pen.setWidthF(2);
		bar->setName(barName + " (" + QString::number(m_tests.at(i).testcase().duration(), 'f', 4) + "s)");
		pen.setBrush(Factory::ColorFactory::color(static_cast<int>(i), 125, 255));
		bar->setPen(pen);
		bar->setBrush(Factory::ColorFactory::color(static_cast<int>(i), 125, 180));
		QVector<double> data;
		data.resize(ticks.length());
		data.fill(0);
		data[i] = m_tests.at(i).testcase().duration();
		bar->setData(ticks, data);
		m_testBars.push_back(bar);
	}
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

