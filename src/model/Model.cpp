#include "Model.h"

Model::Model(QObject *parent)
	: QObject(parent),
      m_dnsBrowser(this)
{
	connect(&m_dnsBrowser, SIGNAL(error(const QString&)),
			  this, SIGNAL(dnsBrowserError(const QString&)));
}

