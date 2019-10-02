#include <assert.h>
#include "structure.h"
#include "printers.h"

int main(int argc, char** argv) {

    automaton* a = NULL;

    a = init(4, 10, 3, 9, "0100000000", &default_print);

    start(a);
    destroy(&a);

    return EXIT_SUCCESS;
}
