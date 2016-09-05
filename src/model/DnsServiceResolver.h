#pragma once

#include <QObject>
#include <QSocketNotifier>
#include <QHostInfo>
#include "DnsServiceRecord.h"
#include "dns_sd.h"

class DnsServiceResolver : public QObject
{
    Q_OBJECT

private:
    DNSServiceRef   m_ref;
    int             m_port;

    static void DNSSD_API resolveCallback(DNSServiceRef, DNSServiceFlags, uint32_t,
                                          DNSServiceErrorType errorCode,
                                          const char *, const char *hosttarget,
                                          uint16_t port, uint16_t, const unsigned char *,
                                          void *context);

public:
    DnsServiceResolver(QObject *parent = 0);

    void resolveRecord(const DnsServiceRecord& record);

signals:
    void error(const QString& );
    void resolved(const QHostInfo& hostInfo, int port);

private slots:
    void onSockNotifierActivated();
    void onHostInfoLookup(const QHostInfo& hostInfo);
    void cleanupResolve();
};
