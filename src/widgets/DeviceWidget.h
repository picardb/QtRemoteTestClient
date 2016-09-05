#pragma once

#include <QWidget>
#include <QTableView>

#include "../model/Model.h"

class DeviceWidget : public QWidget
{
	Q_OBJECT

private:
    Model        *m_pModel;

    QTableView   *m_pDeviceList;

protected:
	void showEvent(QShowEvent *event);

public:
    DeviceWidget(Model *pModel, QWidget *parent = 0);

private slots:
    void onDeviceListDoubleClicked(const QModelIndex& index);
};
