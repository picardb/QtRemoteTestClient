#pragma once

#include <QMainWindow>

#include "MainWidget.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

private:
    MainWidget  *m_pCentralWidget;

public:
    MainWindow(QWidget *parent = 0);
	~MainWindow();
};
