#include "MainWidget.h"

#include <QHBoxLayout>
#include <QMessageBox>
#include "DeviceWidget.h"

MainWidget::MainWidget(Model *pModel, QWidget *parent)
	: QWidget(parent),
	  m_pModel(pModel)
{
	/* Create layout */
	QHBoxLayout *pLayout = new QHBoxLayout;

	/* Create children widgets */
	DeviceWidget *pDeviceWidget = new DeviceWidget(pModel);
	pLayout->addWidget(pDeviceWidget);

	/* Connect model signals */
	connect(pModel, SIGNAL(dnsBrowserError(const QString&)),
			  this, SLOT(onDnsBrowserError(const QString&)));

	/* Setup widget */
	setLayout(pLayout);
}

void MainWidget::onDnsBrowserError(const QString &str) {
	QMessageBox::critical(this, "DNS Service error", str);
}
