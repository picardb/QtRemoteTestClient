#pragma once

#include <QWidget>
#include <QLabel>
#include <QTableView>
#include <QHostAddress>

class DeviceWidget : public QWidget
{
	Q_OBJECT

private:
    QLabel      *m_pStatusLabel;
    QTableView   *m_pDeviceList;

protected:
	void showEvent(QShowEvent *event);

public:
     DeviceWidget(QWidget *parent = 0);

private slots:
    void onDeviceListDoubleClicked(const QModelIndex& index);
    void onNetworkResolving(const QString& name);
    void onNetworkConnecting(const QHostAddress& address, int port);
    void onNetworkConnected(const QString& deviceName);
    void onNetworkDisconnected();
};
