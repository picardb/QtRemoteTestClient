#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	/* Create central widget */
    m_pCentralWidget = new MainWidget;
	setCentralWidget(m_pCentralWidget);
}

MainWindow::~MainWindow()
{

}
