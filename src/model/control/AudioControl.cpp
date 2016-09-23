#include "AudioControl.h"

#include "model/network/Request.h"
#include "model/Model.h"

AudioControl::AudioControl()
{

}

void AudioControl::raiseVolume(unsigned char percentage) {
    /* Prepare request */
    Request req;
    req.system = SYSTEM_ID;
    req.command = CMD_ID_RAISE_VOL;
    req.length = 1;
    req.data.append((char)percentage);

    /* Send request */
    Model::network().sendRequest(req);
}

void AudioControl::lowerVolume(unsigned char percentage) {
    /* Prepare request */
    Request req;
    req.system = SYSTEM_ID;
    req.command = CMD_ID_LOWER_VOL;
    req.length = 1;
    req.data.append((char)percentage);

    /* Send request */
    Model::network().sendRequest(req);
}

void AudioControl::setVolume(unsigned char percentage) {
    /* Prepare request */
    Request req;
    req.system = SYSTEM_ID;
    req.command = CMD_ID_SET_VOL;
    req.length = 1;
    req.data.append((char)percentage);

    /* Send request */
    Model::network().sendRequest(req);
}
