#pragma once

#include <qcustomplot.h>

#include <core/containers/test-case-info-container.h>

#include <QMap>
#include  <list>
#include <memory>

namespace Widget {

	class Plot : public QCustomPlot {
	public:
		explicit Plot(QWidget *parent = nullptr);
		virtual ~Plot();

		void insert(Container::TestCaseContainer &test);

		QCPPlotTitle *title();
		QCPPlotTitle *subtitle();
		QCPBars *bars(const QString &name);

	protected:
		void setGrid();

		void reset();

	private:
		std::vector<Container::TestCaseContainer> m_tests;
		std::vector<QCPBars *> m_testBars;

		QMap <QString, QCPBars *> m_bars;

		QCPPlotTitle *m_title;
		QCPPlotTitle *m_subtitle;
	};

}
