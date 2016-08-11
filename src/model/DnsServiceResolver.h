#pragma once

#include <QObject>

class DnsServiceResolver : public QObject
{
    Q_OBJECT

public:
    DnsServiceResolver();

    resolveService();
};
