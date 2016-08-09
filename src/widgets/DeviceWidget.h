#pragma once

#include <QWidget>
#include <QListWidget>

#include "../model/Model.h"

class DeviceWidget : public QWidget
{
	Q_OBJECT

private:
    Model           *m_pModel;

    QListWidget     *m_pDeviceList;

protected:
	void showEvent(QShowEvent *event);

public:
	DeviceWidget(Model *pModel, QWidget *parent = 0);

private slots:
	void onDnsBrowserListUpdated();
};
