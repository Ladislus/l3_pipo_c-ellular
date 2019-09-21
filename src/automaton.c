#include <assert.h>
#include "structure.h"

int main(int argc, char** argv) {

    automaton* a = NULL;

    if(argc <= 1) {
        printf("\nNo argument provided, taking default rule\n");
        a = init(DEFAULT_RULE);
    }
    else {
        int rule;    
        sscanf(argv[1], "%d", &rule);
        assert(rule < 256);
        a = init(rule);
    } 
    
    start(a);
    destroy(&a);

    return EXIT_SUCCESS;
}