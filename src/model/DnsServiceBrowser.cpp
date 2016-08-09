#include "DnsServiceBrowser.h"

#include <QApplication>
#include "../constants.h"

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



void DnsServiceBrowser::browseCallback(DNSServiceRef , DNSServiceFlags flags, uint32_t , DNSServiceErrorType errorCode, const char *serviceName, const char *regtype, const char *replyDomain, void *context)
{
    DnsServiceBrowser *pBrowser = static_cast<DnsServiceBrowser*>(context);

	if (errorCode != kDNSServiceErr_NoError) {
        emit pBrowser->error(QString("Error while browsing for services (error code = %1)").arg(errorCode));
		return;
	}

	DnsServiceRecord rec(serviceName, regtype, replyDomain);
	/* Add new service record to the list */
	if (flags & kDNSServiceFlagsAdd) {
        pBrowser->m_recordList.append(rec);
	}
	/* Remove service record from the list */
	else {
        if (pBrowser->m_recordList.contains(rec)) {
            pBrowser->m_recordList.removeAll(rec);
		}
	}

	/* If necessary, emit the updated signal */
	if (!(flags & kDNSServiceFlagsMoreComing)) {
        emit pBrowser->listUpdated();
	}
}

void DnsServiceBrowser::onSockNotifierActivated() {
	DNSServiceProcessResult(m_serviceRef);
}
