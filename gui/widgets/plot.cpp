#include <gui/widgets/plot.h>
#include <core/enums/font-type.h>
#include <core/factories/color-factory.h>

#include <algorithm>

using namespace Enum;
using namespace Widget;

Plot::Plot(const QString &testName, QWidget *parent)
	: QCustomPlot(parent)
	, m_testName(testName)

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
	legend->setBrush(QColor(255, 255, 255, 150));
	QPen legendPen;
	legendPen.setColor(QColor(130, 130, 130, 150));
	legend->setBorderPen(legendPen);
	xAxis->setRange(0, 0.01);
	setGrid();
	setGuiFont();
	setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

Plot::~Plot() {
}

void Plot::insert(Container::TestCaseContainer &test) {
	m_tests.push_back(test);
}

void Plot::generate() {
	std::sort(m_tests.begin(), m_tests.end(),
	[](const Container::TestCaseContainer & a, const Container::TestCaseContainer & b) {
		return a.constTestcase().duration() < b.constTestcase().duration();
	});
	QVector <double> ticks;
	QVector <QString> labels;
	double max = 0;

	for (size_t i = 0; i < m_tests.size(); ++i) {
		const Container::CompilerInfoContainer &compiler = m_tests.at(i).compiler();
		const Container::PlatformInfoContainer &platform = m_tests.at(i).platform();
		const Container::TestCaseInfoContainer &testcase = m_tests.at(i).testcase();
		const QString compilerName = name(compiler.id());
		ticks << i;
		labels << QString("%1/%2 %3 %4\n%5").arg(
		         name(platform.platform()),
		         name(platform.arch()),
		         name(compiler.id()),
		         compiler.constVersion().toString(),
		         compiler.flags().replace(' ', '\n'));
		auto bar = new QCPBars(yAxis, xAxis);
		QPen pen;
		pen.setWidthF(2);
		bar->setName(QString::number(testcase.duration(), 'f', 4) + "s");
		pen.setBrush(Factory::ColorFactory::color(static_cast<int>(i), 125, 255));
		bar->setPen(pen);
		bar->setBrush(Factory::ColorFactory::color(static_cast<int>(i), 125, 180));
		QVector<double> data;
		data.resize(ticks.length());
		data.fill(0);
		data[i] = testcase.duration();
		bar->setData(ticks, data);
		m_testBars.push_back(bar);

		if (max < testcase.duration())
			max = testcase.duration();

		if (xAxis->range().upper < testcase.duration())
			xAxis->setRange(0, testcase.duration() + (testcase.duration() * 0.25));
	}

	yAxis->setTickVector(ticks);
	yAxis->setTickVectorLabels(labels);
	yAxis->setRange(-1, m_tests.size());
	size_t i = m_testBars.size();

	do {
		QCPBars *bar = m_testBars.at(--i);
		const Container::TestCaseInfoContainer &testcase = m_tests.at(i).testcase();

		if (i != m_testBars.size() - 1)
			bar->setName(bar->name() + ", +"
			             + QString::number(static_cast<int>(max / testcase.duration() * 100) - 100) + "%");

		addPlottable(bar);
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

void Plot::setGuiFont() {
	legend->setFont(factory(FontType::Legend));
	m_subtitle->setFont(factory(FontType::Subtitle));
	m_title->setFont(factory(FontType::Title));
	xAxis->setLabelFont(factory(FontType::YAxis));
	xAxis->setTickLabelFont(factory(FontType::XAxis));
	yAxis->setTickLabelFont(factory(FontType::YAxis));
}

void Plot::setPaperFont() {
	legend->setFont(paper(FontType::Legend));
	m_subtitle->setFont(paper(FontType::Subtitle));
	m_title->setFont(paper(FontType::Title));
	xAxis->setLabelFont(paper(FontType::YAxis));
	xAxis->setTickLabelFont(paper(FontType::XAxis));
	yAxis->setTickLabelFont(paper(FontType::YAxis));
}

void Plot::reset() {
	yAxis->grid()->setVisible(true);
	yAxis->setAutoTickLabels(false);
	yAxis->setAutoTicks(false);
	yAxis->setRange(-2, 1);
	yAxis->setSubTickCount(0);
	yAxis->setTickLabelRotation(0);
	yAxis->setTickLength(0, 4);
	yAxis->setTickVector({});
	yAxis->setTickVectorLabels({});
}

QString Plot::testName() const {
	return m_testName;
}

void Widget::Plot::saveToFile(const QString &fileName) {
	Plot plot(m_testName, nullptr);

	for (auto &test : m_tests)
		plot.insert(test);

	plot.setPaperFont();
	plot.generate();
	plot.title()->setFont(m_title->font());
	plot.title()->setText(m_title->text());
	plot.title()->setTextColor(m_title->textColor());
	plot.subtitle()->setFont(m_subtitle->font());
	plot.subtitle()->setText(m_subtitle->text());
	plot.subtitle()->setTextColor(m_subtitle->textColor());
	QSize size(2000, 1125);
	QPixmap pixmap(size);
	plot.resize(size);
	plot.render(&pixmap, {}, {0, 0, size.width(), size.height()});
	pixmap.save(fileName, "PNG");
}
