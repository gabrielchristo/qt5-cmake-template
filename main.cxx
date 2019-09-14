
#include <QApplication>
#include <QFile>
#include "mainwindow.h"

int main(int argc, char **argv){

	QApplication app(argc, argv);
	app.setApplicationName("Generic Qt/CMake Project");
	app.setWindowIcon(QIcon(":/qt_logo.png"));
	
	QFile styleFile(":/style.qss");
	styleFile.open(QFile::ReadOnly);
	QString style(styleFile.readAll());
	app.setStyleSheet(style);
	
	MainWindow w;
	w.setWindowTitle("Generic Qt/CMake Project");
	w.show();

	return app.exec();
}