#pragma once

#include <QObject>

#include "network/Network.h"
#include "control/Control.h"

class Model : public QObject
{
	Q_OBJECT

private:
    static Network m_network;
    static Control m_control;

public:
    static Network& network() { return m_network; }
    static Control& control() { return m_control; }
};
