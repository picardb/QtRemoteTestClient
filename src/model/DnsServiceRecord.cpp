#include "DnsServiceRecord.h"

DnsServiceRecord::DnsServiceRecord()
	: m_name(""),
	  m_type(""),
	  m_domain("")
{

}

DnsServiceRecord::DnsServiceRecord(const char name[], const char type[], const char domain[])
	: m_name(name),
	  m_type(type),
	  m_domain(domain)
{

}

DnsServiceRecord::DnsServiceRecord(const DnsServiceRecord &other)
	: m_name(other.name()),
	  m_type(other.type()),
	  m_domain(other.domain())
{

}

DnsServiceRecord& DnsServiceRecord::operator=(const DnsServiceRecord& other) {
	m_name = other.name();
	m_type = other.type();
	m_domain = other.domain();

	return *this;
}

bool DnsServiceRecord::operator==(const DnsServiceRecord& other) const {
	return (m_name == other.name()
			  && m_type == other.type()
			  && m_domain == other.domain());
}
