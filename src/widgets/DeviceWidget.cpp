#include "DeviceWidget.h"

#include <QGroupBox>
#include <QVBoxLayout>
#include <QHeaderView>
#include "model/Model.h"

DeviceWidget::DeviceWidget(QWidget *parent)
    : QWidget(parent)
{
	/* Create layouts */
	QVBoxLayout *pMainLayout = new QVBoxLayout;
	QVBoxLayout *pBoxLayout = new QVBoxLayout;

    /* Create status label */
    m_pStatusLabel = new QLabel("Status: Disconnected");
    pMainLayout->addWidget(m_pStatusLabel);

    /* Create device table */
    QGroupBox *pDeviceBox = new QGroupBox("Available devices");
    m_pDeviceList = new QTableView;
    m_pDeviceList->setModel(Model::network().getDnsRecordList());
    m_pDeviceList->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_pDeviceList->setSelectionMode(QAbstractItemView::SingleSelection);
    m_pDeviceList->setShowGrid(false);
    m_pDeviceList->verticalHeader()->setVisible(false);
    connect(m_pDeviceList, SIGNAL(doubleClicked(const QModelIndex&)),
            this, SLOT(onDeviceListDoubleClicked(const QModelIndex&)));
    pBoxLayout->addWidget(m_pDeviceList);
	pDeviceBox->setLayout(pBoxLayout);
	pMainLayout->addWidget(pDeviceBox);

    /* Connect network signals */
    connect(&Model::network(), SIGNAL(resolvingDnsRecord(QString)),
            this, SLOT(onNetworkResolving(QString)));
    connect(&Model::network(), SIGNAL(connecting(QHostAddress,int)),
            this, SLOT(onNetworkConnecting(QHostAddress,int)));
    connect(&Model::network(), SIGNAL(connected(QHostAddress,int)),
            this, SLOT(onNetworkConnected(QHostAddress,int)));
    connect(&Model::network(), SIGNAL(disconnected()),
            this, SLOT(onNetworkDisconnected()));

	/* Setup widget */
    setLayout(pMainLayout);
}

void DeviceWidget::showEvent(QShowEvent *event)
{
	QWidget::showEvent(event);
    Model::network().startDnsBrowsing();
}

void DeviceWidget::onDeviceListDoubleClicked(const QModelIndex &index)
{
    Model::network().connectToDevice(index.row());
}

void DeviceWidget::onNetworkResolving(const QString &name) {
    m_pStatusLabel->setText("Status: Resolving DNS Service " + name);
}

void DeviceWidget::onNetworkConnecting(const QHostAddress &address, int port) {
    m_pStatusLabel->setText("Status: Connecting to " + address.toString() + ":" + QString::number(port));
}

void DeviceWidget::onNetworkConnected(const QHostAddress &address, int port) {
    m_pStatusLabel->setText("Status: Connected to " + address.toString() + ":" + QString::number(port));
}

void DeviceWidget::onNetworkDisconnected() {
    m_pStatusLabel->setText("Status: Disconnected");
}
