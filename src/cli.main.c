#include <stdlib.h>
#include <stdio.h>


#define MAGIC_PACKET_LENGTH 102

int main(int argc, char **argv) {

    if ( argc != 2 )
    {
        perror("Please provide one and only mac address\n");
        exit(-1);
    }

    unsigned char packet[MAGIC_PACKET_LENGTH];
    createMagicPacket(packet, argv[1]);
    sendWOLPacket(packet);
    printf("Packet sent!\n");

}