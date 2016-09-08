#pragma once

#include <QObject>

#include "network/Network.h"

class Model : public QObject
{
	Q_OBJECT

private:
    static Network m_network;

public:
    static Network& network() { return m_network; }
};
