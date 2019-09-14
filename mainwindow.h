
#include <QMainWindow>
#include <QLabel>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow, public Ui::MainWindow {

	Q_OBJECT

public:
	MainWindow();
	~MainWindow();


};