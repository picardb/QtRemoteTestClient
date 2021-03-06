#include "DnsServiceBrowser.h"

#include <QApplication>
#include "constants.h"

DnsServiceBrowser::DnsServiceBrowser(QObject *parent)
	: QObject(parent)
{

}

void DnsServiceBrowser::start() {
	/* Start browsing */
    DNSServiceErrorType result = DNSServiceBrowse(&m_serviceRef,
                                                  0,
                                                  0,
                                                  DNS_SD_REG_TYPE.toUtf8(),
                                                  NULL,
                                                  browseCallback,
                                                  this);
	if (result != kDNSServiceErr_NoError) {
		emit error(QString("Cannot start browsing for services (error code = %1)").arg(result));
		return;
	}

	/* Connect to a socket notifier */
	int sockFD = DNSServiceRefSockFD(m_serviceRef);
	if (sockFD == -1) {
		emit error(QString("Cannot retrieve DNS-SD socket"));
		return;
	}
	QSocketNotifier *pNotifier = new QSocketNotifier(sockFD, QSocketNotifier::Read, this);
	connect(pNotifier, SIGNAL(activated(int)), this, SLOT(onSockNotifierActivated()));
}



void DnsServiceBrowser::browseCallback(DNSServiceRef , DNSServiceFlags flags,
                                       uint32_t interfaceIndex, DNSServiceErrorType errorCode,
                                       const char *serviceName, const char *regtype,
                                       const char *replyDomain, void *context)
{
    DnsServiceBrowser *pBrowser = static_cast<DnsServiceBrowser*>(context);

	if (errorCode != kDNSServiceErr_NoError) {
        emit pBrowser->error(QString("Error while browsing for services (error code = %1)").arg(errorCode));
		return;
    }

    DnsServiceRecord rec(serviceName, regtype, replyDomain, interfaceIndex);
	/* Add new service record to the list */
	if (flags & kDNSServiceFlagsAdd) {
        pBrowser->m_recordList.add(rec);
	}
	/* Remove service record from the list */
	else {
        pBrowser->m_recordList.remove(rec);
    }
}

void DnsServiceBrowser::onSockNotifierActivated() {
    /* Call DNS_SD API */
    DNSServiceProcessResult(m_serviceRef);
}
