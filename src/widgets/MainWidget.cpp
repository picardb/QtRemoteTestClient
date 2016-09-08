#include "MainWidget.h"

#include <QHBoxLayout>
#include <QMessageBox>
#include "DeviceWidget.h"
#include "model/Model.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
	/* Create layout */
	QHBoxLayout *pLayout = new QHBoxLayout;

	/* Create children widgets */
    DeviceWidget *pDeviceWidget = new DeviceWidget;
	pLayout->addWidget(pDeviceWidget);

	/* Connect model signals */
    connect(&Model::network(), SIGNAL(error(QString)),
            this, SLOT(onNetworkError(QString)));

	/* Setup widget */
	setLayout(pLayout);
}

void MainWidget::onNetworkError(const QString &msg) {
    QMessageBox::critical(this, "Network error", msg);
}
