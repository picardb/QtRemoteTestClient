#pragma once

#include <QObject>

#include "network/Network.h"
#include "request/Request.h"

class Model : public QObject
{
	Q_OBJECT

private:
    static Network m_network;
    static Request m_request;

public:
    static Network& network() { return m_network; }
    static Request& request() { return m_request; }
};
