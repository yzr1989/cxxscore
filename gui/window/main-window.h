#pragma once

#include <QMainWindow>

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
		Ui::MainWindow *ui;
	};

}
