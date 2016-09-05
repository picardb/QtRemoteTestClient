#pragma once

#include <QObject>

#include "DnsServiceBrowser.h"
#include "DnsServiceResolver.h"

class Model : public QObject
{
	Q_OBJECT

private:
    DnsServiceBrowser   m_dnsBrowser;
    DnsServiceResolver  m_dnsResolver;

public:
    Model(QObject *parent = 0);

	/* DnsServiceBrowser methods */
    DnsServiceRecordList* dnsBrowserGetRecordList() { return m_dnsBrowser.getRecordList(); }
    const DnsServiceRecord& dnsBrowserGetRecord(int index) const { return m_dnsBrowser.getRecord(index); }
	void dnsBrowserStart() { m_dnsBrowser.start(); }

    /* DnsServiceResolver methods */
    void dnsResolverResolveRecord(const DnsServiceRecord& record) { m_dnsResolver.resolveRecord(record); }

signals:
    /* DnsServiceBrowser signals */
	void dnsBrowserError(const QString& );

    /* DnsServiceResolver signals */
    void dnsResolverError(const QString& );
    void dnsResolverResolved(const QHostInfo& hostInfo, int port);
};
