#include "Request.h"

#include "model/Model.h"

Request::Request(QObject *parent)
    : QObject(parent)
{

}


void Request::raiseAudio(unsigned char percentage) {
    QByteArray packet;

    /* Command */
    packet.append((char)CMD_AUDIO);

    /* Command specifier */
    packet.append((char)CMD_SPEC_RAISE);

    /* Size */
    packet.append((char)0);
    packet.append((char)1);

    /* Data */
    packet.append((char)percentage);

    /* Send */
    Model::network().sendPacket(packet);
}


void Request::lowerAudio(unsigned char percentage) {
    QByteArray packet;

    /* Command */
    packet.append((char)CMD_AUDIO);

    /* Command specifier */
    packet.append((char)CMD_SPEC_LOWER);

    /* Size */
    packet.append((char)0);
    packet.append((char)1);

    /* Data */
    packet.append((char)percentage);

    /* Send */
    Model::network().sendPacket(packet);
}


void Request::setAudio(unsigned char percentage) {
    QByteArray packet;

    /* Command */
    packet.append((char)CMD_AUDIO);

    /* Command specifier */
    packet.append((char)CMD_SPEC_SET);

    /* Size */
    packet.append((char)0);
    packet.append((char)1);

    /* Data */
    packet.append((char)percentage);

    /* Send */
    Model::network().sendPacket(packet);
}
