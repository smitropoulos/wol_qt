#include <stdlib.h>
#include <stdio.h>
#include <inet_spec_packet.h>
#include <inet_oper.h>


#define MAGIC_PACKET_LENGTH 102

int main(int argc, char **argv) {

    if ( argc != 2 )
    {
        perror("Please provide one and only mac address\n");
        exit(3);
    }

    unsigned char packet[MAGIC_PACKET_LENGTH];
    createMagicPacket(packet, argv[1]);
    if ( !sendWOLPacket(packet))
    {
        printf("Packet sent!\n");
    }
}