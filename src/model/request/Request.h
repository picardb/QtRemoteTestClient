#pragma once

#include <QObject>

class Request : public QObject {
    Q_OBJECT

    enum Command {
        CMD_AUDIO = 1
    };

    enum CommandSpecifier {
        CMD_SPEC_RAISE = 1,
        CMD_SPEC_LOWER = 2,
        CMD_SPEC_SET   = 3
    };

public:
    Request(QObject *parent = 0);

    void raiseAudio(unsigned char percentage);
    void lowerAudio(unsigned char percentage);
    void setAudio(unsigned char percentage);
};
