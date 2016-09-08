#include "DnsServiceRecord.h"

DnsServiceRecord::DnsServiceRecord()
	: m_name(""),
	  m_type(""),
      m_domain(""),
      m_interfaceIndex(0)
{

}

DnsServiceRecord::DnsServiceRecord(const char name[], const char type[], const char domain[], const quint32 interfaceIndex)
	: m_name(name),
	  m_type(type),
      m_domain(domain),
      m_interfaceIndex(interfaceIndex)
{

}

DnsServiceRecord::DnsServiceRecord(const DnsServiceRecord &other)
	: m_name(other.name()),
	  m_type(other.type()),
      m_domain(other.domain()),
      m_interfaceIndex(other.interfaceIndex())
{

}

DnsServiceRecord& DnsServiceRecord::operator=(const DnsServiceRecord& other) {
	m_name = other.name();
	m_type = other.type();
	m_domain = other.domain();
    m_interfaceIndex = other.interfaceIndex();

	return *this;
}

bool DnsServiceRecord::operator==(const DnsServiceRecord& other) const {
	return (m_name == other.name()
            && m_type == other.type()
            && m_domain == other.domain()
            && m_interfaceIndex == other.interfaceIndex());
}

QString DnsServiceRecord::membersName(int index)
{
    switch (index) {
    case MEMBER_INDEX_NAME:
        return "Name";

    case MEMBER_INDEX_TYPE:
        return "Type";

    case MEMBER_INDEX_DOMAIN:
        return "Domain";

    case MEMBER_INDEX_INTERFACE:
        return "Interface";

    default:
        return "???";
    }
}
