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
    //m_pDeviceList->setModelColumn(DnsServiceRecord::MEMBER_INDEX_NAME);
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
