#include "Model.h"

Model::Model(QObject *parent)
	: QObject(parent),
      m_dnsBrowser(this),
      m_dnsResolver(this)
{
    /* Forward children signals */
	connect(&m_dnsBrowser, SIGNAL(error(const QString&)),
			  this, SIGNAL(dnsBrowserError(const QString&)));
    connect(&m_dnsResolver, SIGNAL(error(const QString&)),
            this, SIGNAL(dnsResolverError(const QString&)));
    connect(&m_dnsResolver, SIGNAL(resolved(const QHostInfo&, int)),
            this, SIGNAL(dnsResolverResolved(const QHostInfo& ,int)));
}

