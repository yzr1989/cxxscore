#pragma once

#include <core/managers/file-manager.h>

#include <QMainWindow>

namespace Widget {
	class Plot;
}

namespace Window {

	namespace Ui {
		class MainWindow;
	}

	class MainWindow : public QMainWindow {
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

		void loadFromFile(const QString &fileName);

	private:
		Manager::FileManager m_manager;
		Ui::MainWindow *ui;
	};

}
