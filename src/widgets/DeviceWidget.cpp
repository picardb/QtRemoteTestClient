#include "DeviceWidget.h"

#include <QGroupBox>
#include <QVBoxLayout>
#include <QHeaderView>

DeviceWidget::DeviceWidget(Model *pModel, QWidget *parent)
	: QWidget(parent),
	  m_pModel(pModel)
{
	/* Create layouts */
	QVBoxLayout *pMainLayout = new QVBoxLayout;
	QVBoxLayout *pBoxLayout = new QVBoxLayout;

	/* Create children widgets */
    QGroupBox *pDeviceBox = new QGroupBox("Available devices");
    m_pDeviceList = new QTableView;
    m_pDeviceList->setModel(pModel->dnsBrowserGetRecordList());
    m_pDeviceList->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_pDeviceList->setSelectionMode(QAbstractItemView::SingleSelection);
    m_pDeviceList->setShowGrid(false);
    m_pDeviceList->verticalHeader()->setVisible(false);
    connect(m_pDeviceList, SIGNAL(doubleClicked(const QModelIndex&)),
            this, SLOT(onDeviceListDoubleClicked(const QModelIndex&)));
    pBoxLayout->addWidget(m_pDeviceList);
	pDeviceBox->setLayout(pBoxLayout);
	pMainLayout->addWidget(pDeviceBox);

	/* Setup widget */
    setLayout(pMainLayout);
}

void DeviceWidget::showEvent(QShowEvent *event)
{
	QWidget::showEvent(event);
	m_pModel->dnsBrowserStart();
}

void DeviceWidget::onDeviceListDoubleClicked(const QModelIndex &index)
{
    m_pModel->dnsResolverResolveRecord(m_pModel->dnsBrowserGetRecord(index.row()));
}
