#pragma once

class AudioControl
{
private:
    static const unsigned char SYSTEM_ID        = 0x01;
    static const unsigned char CMD_ID_RAISE_VOL = 0x01;
    static const unsigned char CMD_ID_LOWER_VOL = 0x02;
    static const unsigned char CMD_ID_SET_VOL   = 0x03;

public:
    AudioControl();

    void raiseVolume(unsigned char percentage);
    void lowerVolume(unsigned char percentage);
    void setVolume(unsigned char percentage);
};
