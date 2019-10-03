#include <assert.h>
#include "structure.h"
#include "printers.h"

int main(int argc, char** argv) {

    automaton* a = NULL;

    a = init_file("/home/ladislus/Bureau/C-ellular-project/config.txt", &default_print);

    start(a);
    destroy(&a);

    return EXIT_SUCCESS;
}
