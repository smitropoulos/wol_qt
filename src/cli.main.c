#include "cli.main.h"


int main(int argc, char **argv) {

    return createAndSentWOL(argc, argv[1]);
}