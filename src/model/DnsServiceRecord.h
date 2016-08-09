#pragma once

#include <QString>

class DnsServiceRecord
{
private:
	QString	m_name;
	QString	m_type;
	QString	m_domain;

public:
	DnsServiceRecord();
	DnsServiceRecord(const char name[], const char type[], const char domain[]);
	DnsServiceRecord(const DnsServiceRecord& other);

	DnsServiceRecord& operator=(const DnsServiceRecord& other);
	bool operator==(const DnsServiceRecord& other) const;

	const QString& name() const { return m_name; }
	const QString& type() const { return m_type; }
	const QString& domain() const { return m_domain; }
};
