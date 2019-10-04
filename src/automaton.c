#include <assert.h>
#include "structure.h"
#include "menu.h"

int main(int argc, char** argv) {

    automaton* a = NULL;

    a = menu();

    start(a);
    destroy(&a);

    return EXIT_SUCCESS;
}
