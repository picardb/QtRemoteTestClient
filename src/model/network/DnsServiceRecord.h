#pragma once

#include <QString>

class DnsServiceRecord
{
private:
	QString	m_name;
	QString	m_type;
	QString	m_domain;
    quint32 m_interfaceIndex;

public:
    enum membersIndexes {
        MEMBER_INDEX_NAME = 0,
        MEMBER_INDEX_TYPE = 1,
        MEMBER_INDEX_DOMAIN = 2,
        MEMBER_INDEX_INTERFACE = 3
    };

	DnsServiceRecord();
    DnsServiceRecord(const char name[], const char type[], const char domain[], const quint32 interfaceIndex);
	DnsServiceRecord(const DnsServiceRecord& other);

	DnsServiceRecord& operator=(const DnsServiceRecord& other);
	bool operator==(const DnsServiceRecord& other) const;

	const QString& name() const { return m_name; }
	const QString& type() const { return m_type; }
	const QString& domain() const { return m_domain; }
    quint32 interfaceIndex() const { return m_interfaceIndex; }

    static int membersCount() { return 4; }
    static QString membersName(int index);
};
