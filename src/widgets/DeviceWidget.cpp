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
    m_pDeviceList = new QListWidget;
    pBoxLayout->addWidget(m_pDeviceList);
	pDeviceBox->setLayout(pBoxLayout);
	pMainLayout->addWidget(pDeviceBox);

	/* Setup widget */
	setLayout(pMainLayout);

	/* Connect model signals */
	connect(pModel, SIGNAL(dnsBrowserListUpdated()),
			  this, SLOT(onDnsBrowserListUpdated()));
}

void DeviceWidget::showEvent(QShowEvent *event)
{
	QWidget::showEvent(event);
	m_pModel->dnsBrowserStart();
}

void DeviceWidget::onDnsBrowserListUpdated() {
    m_pDeviceList->clear();

	/* Get the new list of services and add all to the list widget */
	const QVector<DnsServiceRecord>& list = m_pModel->dnsBrowserGetList();
    for (int i = 0 ; i < list.size() ; i++) {
        m_pDeviceList->addItem(list[i].name());
	}
}
