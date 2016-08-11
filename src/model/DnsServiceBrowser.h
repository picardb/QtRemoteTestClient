#pragma once

#include <QObject>
#include <QVector>
#include <QSocketNotifier>
#include "dns_sd.h"
#include "DnsServiceRecordList.h"

class DnsServiceBrowser : public QObject
{
	Q_OBJECT

private:
    DnsServiceRecordList	m_recordList;
    DNSServiceRef			m_serviceRef;
    QSocketNotifier			*m_pNotifier;

	static void DNSSD_API browseCallback(DNSServiceRef sdRef, DNSServiceFlags flags,
													 uint32_t interfaceIndex, DNSServiceErrorType errorCode,
													 const char *serviceName, const char *regtype,
													 const char *replyDomain, void *context );


public:
	DnsServiceBrowser(QObject *parent = 0);

    void start();
    DnsServiceRecordList* getRecordList() { return &m_recordList; }

signals:
	void error(const QString& );

private slots:
	void onSockNotifierActivated();
};
