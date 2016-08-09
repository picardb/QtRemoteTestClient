#include "Model.h"

Model::Model(QObject *parent)
	: QObject(parent),
	  m_dnsBrowser(this)
{
	/* Connect children signals */
	connect(&m_dnsBrowser, SIGNAL(listUpdated()),
			  this, SIGNAL(dnsBrowserListUpdated()));
	connect(&m_dnsBrowser, SIGNAL(error(const QString&)),
			  this, SIGNAL(dnsBrowserError(const QString&)));
}

