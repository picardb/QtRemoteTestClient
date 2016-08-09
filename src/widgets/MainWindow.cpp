#include "MainWindow.h"

MainWindow::MainWindow(Model *pModel, QWidget *parent)
	: QMainWindow(parent),
	  m_pModel(pModel)
{
	/* Create central widget */
	m_pCentralWidget = new MainWidget(pModel);
	setCentralWidget(m_pCentralWidget);
}

MainWindow::~MainWindow()
{

}
