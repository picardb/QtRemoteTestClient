#pragma once

#include <QObject>

#include "DnsServiceBrowser.h"

class Model : public QObject
{
	Q_OBJECT

private:
	DnsServiceBrowser	m_dnsBrowser;

public:
	Model(QObject *parent = 0);

	/* DnsServiceBrowser methods */
	const QVector<DnsServiceRecord>& dnsBrowserGetList() const { return m_dnsBrowser.getList(); }
	void dnsBrowserStart() { m_dnsBrowser.start(); }

signals:
	/* DnsServiceBrowser signals */
	void dnsBrowserListUpdated();
	void dnsBrowserError(const QString& );
};
