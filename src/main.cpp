#include <QApplication>

#include "widgets/MainWindow.h"
#include "model/Model.h"

int main(int argc, char *argv[])
{
	/* Create application */
	QApplication a(argc, argv);

	/* Create model */
	Model m;

	/* Create main window */
	MainWindow w(&m);
	w.show();

	/* Start */
	return a.exec();
}
