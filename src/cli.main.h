//
// Created by smitropoulos on 18/07/2020.
//

#ifndef _CLI_MAIN_H_
#define _CLI_MAIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <inet_spec_packet.h>
#include <inet_oper.h>


#define MAGIC_PACKET_LENGTH 102
#define MAC_ADDRESS_LENGTH 17

int createAndSentWOL(int argc, char *argv) {

    if ( argc != 2 )
    {
        printf("Please provide one and only mac address\n");
        return (3);
    }

    if ( strlen(argv) != MAC_ADDRESS_LENGTH )
    {
        printf("MAC address has the wrong length\n");
        return -1;
    }

    unsigned char packet[MAGIC_PACKET_LENGTH];
    createMagicPacket(packet, argv);
    if ( !sendWOLPacket(packet))
    {
        printf("Packet sent!\n");
        return 0;
    }
    return 0;
}

#endif //_CLI_MAIN_H_
