#pragma once

#include <QObject>

#include "DnsServiceBrowser.h"

class Model : public QObject
{
	Q_OBJECT

private:
    DnsServiceBrowser       m_dnsBrowser;

public:
    Model(QObject *parent = 0);

	/* DnsServiceBrowser methods */
    DnsServiceRecordList* dnsBrowserGetRecordList() { return m_dnsBrowser.getRecordList(); }
	void dnsBrowserStart() { m_dnsBrowser.start(); }

signals:
    /* DnsServiceBrowser signals */
	void dnsBrowserError(const QString& );
};
