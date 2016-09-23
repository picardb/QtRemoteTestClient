#pragma once

#include <QObject>
#include "AudioControl.h"

class Control : public QObject
{
    Q_OBJECT

private:
    AudioControl m_audio;

public:
    Control(QObject *parent = 0);

    void audioRaiseVolume(unsigned char percentage) { m_audio.raiseVolume(percentage); }
    void audioLowerVolume(unsigned char percentage) { m_audio.lowerVolume(percentage); }
    void audioSetVolume(unsigned char percentage) { m_audio.setVolume(percentage); }
};
