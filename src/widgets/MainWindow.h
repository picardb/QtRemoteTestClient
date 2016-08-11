#pragma once

#include <QMainWindow>

#include "../model/Model.h"
#include "MainWidget.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

private:
    Model		*m_pModel;

    MainWidget  *m_pCentralWidget;

public:
	MainWindow(Model *pModel, QWidget *parent = 0);
	~MainWindow();
};
