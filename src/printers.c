#include "printers.h"

void print(automaton* a) {
    printf("\nRule : %d\n", a->integer_rule);
    printf("Translated rule : %s\n", a->rule);
    printf("Size of the automaton : %d\n", SIZE);
    printf("Number of iterations : %d\n", ITERATIONS);
    for(size_t i = 0; i < ITERATIONS; i++) {
        i < 10 ? printf("|%ld | ", i) : printf("|%ld| ", i);
        print_lign(a, i);
    }
    printf("\n");
}

void print_lign(automaton* a, size_t index) {
    for(size_t i = 1; i < (SIZE - 1); i++) printf("%c", SYMBOLS[a->states[index][i]]);
    printf("%c\n", SYMBOLS[a->states[index][SIZE - 1]]);
}