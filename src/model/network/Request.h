#pragma once

#include <QByteArray>

struct Request {
    unsigned char   system;
    unsigned char   command;
    unsigned int    length;
    QByteArray      data;
};

