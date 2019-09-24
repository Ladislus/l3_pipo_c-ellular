#include <assert.h>
#include "structure.h"
#include "printers.h"

int main(int argc, char** argv) {

    automaton* a = NULL;

    if(argc <= 1) {
        printf("\nNo argument provided, taking default rule\n");
        a = init(DEFAULT_RULE, &default_print);
    }
    else {
        int rule;
        sscanf(argv[1], "%d", &rule);
        assert(rule < 256);
        a = init(rule, &default_print);
    }

    start(a);
    destroy(&a);

    return EXIT_SUCCESS;
}
