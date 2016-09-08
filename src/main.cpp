#include <QApplication>

#include "widgets/MainWindow.h"

int main(int argc, char *argv[])
{
	/* Create application */
    QApplication a(argc, argv);

	/* Create main window */
    MainWindow w;
	w.show();

	/* Start */
	return a.exec();
}
