#include "Network.h"

Network::Network(QObject *parent)
    : QObject(parent),
      m_dnsBrowser(this),
      m_dnsResolver(this),
      m_tcpSocket(this),
      m_isConnecting(false)
{
    /* Connect DNS Resolver signals */
    connect(&m_dnsResolver, SIGNAL(error(QString)),
            this, SLOT(onDnsResolverError()));
    connect(&m_dnsResolver, SIGNAL(resolved(QHostInfo,int)),
            this, SLOT(onDnsResolverResolved(QHostInfo,int)));

    /* Connect TCP socket signals */
    connect(&m_tcpSocket, SIGNAL(connected()),
            this, SLOT(onSocketConnected()));
    connect(&m_tcpSocket, SIGNAL(disconnected()),
            this, SLOT(onSocketDisconnected()));
}

void Network::connectToDevice(int index) {
    /* Check connection status */
    if (m_isConnecting) {
        return;
    }

    /* Check index */
    if (index >= m_dnsBrowser.getRecordList()->rowCount()) {
        return;
    }

    /* If the TCP socket is already connected, disconnect it */
    if (m_tcpSocket.state() == QAbstractSocket::ConnectedState) {
        m_tcpSocket.disconnectFromHost();
    }

    /* Start resolving the DNS record */
    const DnsServiceRecord& record = m_dnsBrowser.getRecord(index);
    m_dnsResolver.resolveRecord(record);
    emit resolvingDnsRecord(record.name());
    m_isConnecting = true;
}

void Network::onDnsResolverError() {
    emit error("Error while resolving DNS service");
    m_isConnecting = false;
    emit disconnected();
}

void Network::onDnsResolverResolved(const QHostInfo &hostInfo, int port) {
    if (hostInfo.addresses().size() < 1) {
        m_isConnecting = false;
        emit disconnected();
        return;
    }

    if (m_tcpSocket.state() != QAbstractSocket::UnconnectedState) {
    //if (m_tcpSocket.isOpen()) {
        m_isConnecting = false;
        emit disconnected();
        return;
    }

    /* Store connection info */
    m_address = hostInfo.addresses().first();
    m_port = port;

    /* Connect to resolved host */
    m_tcpSocket.connectToHost(m_address, m_port);
    emit connecting(m_address, m_port);
}

void Network::onSocketConnected() {
    m_isConnecting = false;
    emit connected(m_address, m_port);
}

void Network::onSocketDisconnected() {
    m_isConnecting = false;
    emit disconnected();
}
