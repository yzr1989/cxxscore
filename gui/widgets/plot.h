#pragma once

#include <qcustomplot.h>

#include <QMap>

namespace Widget {

	class Plot : public QCustomPlot {
	public:
		explicit Plot(QWidget *parent = nullptr);
		virtual ~Plot();

		QCPPlotTitle *title();
		QCPPlotTitle *subtitle();
		QCPBars *bars(const QString &name);

	protected:
		void reset();

	private:
		QMap <QString, QCPBars *> m_bars;

		QCPPlotTitle *m_title;
		QCPPlotTitle *m_subtitle;
	};

}
