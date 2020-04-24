#include <inet_oper.h>
#include <inet_spec_packet.h>
#include <stdio.h>
#include <string>
#include "wol.h"


int sendWolPacket(char *mac) {

    unsigned char packet[MAGIC_PACKET_LENGTH];
    createMagicPacket(packet, mac);
    return sendWOLPacket(packet);
}
