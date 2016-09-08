#include "DnsServiceResolver.h"

#include <QtEndian>

DnsServiceResolver::DnsServiceResolver(QObject *parent)
    : QObject(parent),
      m_ref(NULL),
      m_port(-1)
{

}

void DnsServiceResolver::resolveRecord(const DnsServiceRecord &record) {
    if (m_ref) {
        /* TODO: do something here */
        return;
    }

    /* Call DNS_SD API */
    DNSServiceErrorType result = DNSServiceResolve(&m_ref,
                                                   0,
                                                   record.interfaceIndex(),
                                                   record.name().toUtf8(),
                                                   record.type().toUtf8(),
                                                   record.domain().toUtf8(),
                                                   resolveCallback,
                                                   this);
    if (result != kDNSServiceErr_NoError) {
        emit error(QString("Cannot resolve service (error code = %1)").arg(result));
        return;
    }

    /* Connect to a socket notifier */
    int sockFD = DNSServiceRefSockFD(m_ref);
    if (sockFD == -1) {
        emit error(QString("Cannot retrieve DNS-SD socket"));
        return;
    }
    QSocketNotifier *pNotifier = new QSocketNotifier(sockFD, QSocketNotifier::Read, this);
    connect(pNotifier, SIGNAL(activated(int)), this, SLOT(onSockNotifierActivated()));
}

void DnsServiceResolver::resolveCallback(DNSServiceRef , DNSServiceFlags ,
                     uint32_t , DNSServiceErrorType errorCode,
                     const char *, const char *hosttarget,
                     uint16_t port, uint16_t , const unsigned char *,
                     void *context)
{
    DnsServiceResolver *pResolver = static_cast<DnsServiceResolver *>(context);

    if (errorCode != kDNSServiceErr_NoError) {
        emit pResolver->error(QString("Error while resolving service (error code = %1)").arg(errorCode));
        return;
    }

    pResolver->m_port = qFromBigEndian(port);
    QHostInfo::lookupHost(QString::fromUtf8(hosttarget), pResolver, SLOT(onHostInfoLookup(const QHostInfo&)));
}

void DnsServiceResolver::cleanupResolve() {
    if (m_ref) {
        DNSServiceRefDeallocate(m_ref);
        m_ref = NULL;
        m_port = -1;
    }
}

void DnsServiceResolver::onSockNotifierActivated() {
    /* Call DNS_SD API */
    DNSServiceProcessResult(m_ref);

    /* Delete temporary socket notifier */
    QSocketNotifier *pNotifier = static_cast<QSocketNotifier *>(sender());
    pNotifier->deleteLater();
}

void DnsServiceResolver::onHostInfoLookup(const QHostInfo& hostInfo) {
    emit resolved(hostInfo, m_port);
    QMetaObject::invokeMethod(this, "cleanupResolve", Qt::QueuedConnection);
}
