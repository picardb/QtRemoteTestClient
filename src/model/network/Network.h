#pragma once

#include <QObject>
#include <QTcpSocket>
#include "DnsServiceBrowser.h"
#include "DnsServiceResolver.h"
#include "Request.h"

class Network : public QObject
{
    Q_OBJECT

private:
    DnsServiceBrowser   m_dnsBrowser;
    DnsServiceResolver  m_dnsResolver;
    QTcpSocket			m_tcpSocket;
    QHostAddress        m_address;
    int                 m_port;
    QString             m_deviceName;
    bool                m_isConnecting;

public:
    Network(QObject *parent = 0);

    void startDnsBrowsing() { m_dnsBrowser.start(); }
    DnsServiceRecordList* getDnsRecordList() { return m_dnsBrowser.getRecordList(); }
    void connectToDevice(int index);
    void sendRequest(const Request& request);

private slots:
    void onDnsResolverError();
    void onDnsResolverResolved(const QHostInfo& hostInfo, int port);
    void onSocketConnected();
    void onSocketDisconnected();

signals:
    void resolvingDnsRecord(const QString& name);
    void connecting(const QHostAddress& address, int port);
    void connected(const QString& deviceName);
    void disconnected();
    void error(const QString& msg);
    void packetSent();
};
