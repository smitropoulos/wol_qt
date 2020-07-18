//
// Created by smitropoulos on 18/07/2020.
//

#include "cli.main.h"
#include <iostream>
#include <cassert>


int testCliMode() {

    char macaddress[] = "AA:AA:AA:AA:AA:AA";
    char falseMacAddress[] = "AA";
    char falseMacAddress2[] = "AA:AA:AA:AA:AA:AA:AA:AA:AA:AA:AA:AA";

    assert(("Sending a WOL packet with correct mac address", createAndSentWOL(2, macaddress) == 0));
    assert(("Sending a WOL packet with erroneous mac address", createAndSentWOL(2, falseMacAddress) == -1));
    assert(("Sending a WOL packet with erroneous mac address", createAndSentWOL(2, falseMacAddress2) == -1));
    return 0;
}

int main() {

    return testCliMode();
}