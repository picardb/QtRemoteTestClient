#pragma once

#include <QWidget>

#include "../model/Model.h"

class MainWidget : public QWidget
{
	Q_OBJECT

private:
	Model				*m_pModel;

public:
	MainWidget(Model *pModel, QWidget *parent = 0);

private slots:
	void onDnsBrowserError(const QString& str);
};
