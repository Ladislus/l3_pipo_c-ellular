#include <assert.h>
#include "structure.h"
#include "printers.h"

int main(int argc, char** argv) {

    automaton* a = NULL;

    a = init_file("/home/etud/o2174867/C/C-ellular-project/config.txt", &default_print);
    // a = init(4, 10, 50, 9, "0100000000", &default_print);

    start(a);
    destroy(&a);

    return EXIT_SUCCESS;
}
