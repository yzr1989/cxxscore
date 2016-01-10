#include <gui/widgets/plot.h>

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
	axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignRight);
	legend->setBrush(QColor(255, 255, 255, 200));
	QPen legendPen;
	legendPen.setColor(QColor(130, 130, 130, 200));
	legend->setBorderPen(legendPen);
	QFont legendFont = font();
	legendFont.setPointSize(12);
	legend->setFont(legendFont);
	setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
	xAxis->setRange(0, 1);
}

Plot::~Plot() {
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

