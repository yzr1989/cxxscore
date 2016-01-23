#pragma once

#include <qcustomplot.h>

#include <core/containers/test-case-info-container.h>

#include <QMap>
#include  <list>
#include <memory>

namespace Widget {

	class Plot : public QCustomPlot {
	public:
		explicit Plot(const QString &testName, QWidget *parent = nullptr);
		virtual ~Plot();

		void saveToFile(const QString &fileName);
		void insert(Container::TestCaseContainer &test);

		QCPPlotTitle *title();
		QCPPlotTitle *subtitle();
		QCPBars *bars(const QString &name);

		QString testName() const;

	protected:
		void setGrid();
		void setFont();
		void reset();

	private:
		QString m_testName;

		std::vector<Container::TestCaseContainer> m_tests;
		std::vector<QCPBars *> m_testBars;

		QMap <QString, QCPBars *> m_bars;

		QCPPlotTitle *m_title;
		QCPPlotTitle *m_subtitle;
	};

}
