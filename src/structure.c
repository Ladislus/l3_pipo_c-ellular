#include "structure.h"

automaton* init(unsigned char rule, void (*_printer)(void*)) {
    automaton* returned_automaton = (automaton*)malloc(sizeof(automaton));

    returned_automaton->integer_rule = rule;
    returned_automaton->rule = convert_rule_binary(rule);

    returned_automaton->states = (unsigned char**)malloc(ITERATIONS * sizeof(unsigned char*));
    for(size_t i = 0; i < ITERATIONS; i++) {
        returned_automaton->states[i] = (unsigned char*)calloc(SIZE, sizeof(unsigned char));
    }
    returned_automaton->states[0][SIZE - 1] = 1;

    returned_automaton->_printer = _printer;

    return returned_automaton;
}

void destroy(automaton** a) {
    for(size_t i = 0; i < ITERATIONS; i++) {
        free((*a)->states[i]);
        (*a)->states[i] = NULL;
    }
    free((*a)->states);
    (*a)->states = NULL;

    free((*a)->rule);
    (*a)->rule = NULL;

    free(*a);
}

void start(automaton* a) {
    for(size_t i = 1; i < ITERATIONS; i++) {
        update_state(a, i);
    }
    print(a);
}

unsigned char apply_rule(automaton* a, unsigned char* neighbours) {
    for(size_t i = 0; i < 8; i++) {
        if(compare_state(i, neighbours)) return (a->rule[i] - '0');
    }
    fprintf(stderr, "No matching rule found, exiting ...\n");
    exit(EXIT_FAILURE);
}

bool compare_state(size_t index, unsigned char* tested_state) {
    return ((TABLE[index][0] - '0') == tested_state[0] && (TABLE[index][1] - '0') == tested_state[1] && (TABLE[index][2] - '0') == tested_state[2]);
}

void update_state(automaton* a, size_t iteration) {
    for(size_t i = 0; i < SIZE; i++) {
        unsigned char* neighbours = get_neighbours(a, iteration, i);
        a->states[iteration][i] = apply_rule(a, neighbours);
        free(neighbours);
        neighbours = NULL;
    }
}

unsigned char* get_neighbours(automaton* a, size_t iteration, size_t index) {
    unsigned char* returned_neighbours = (unsigned char*)malloc(3 * sizeof(unsigned char));

    returned_neighbours[0] = (!index ? a->states[iteration - 1][SIZE - 1] : a->states[iteration - 1][index - 1]);
    returned_neighbours[1] = a->states[iteration - 1][index];
    returned_neighbours[2] = (index == (SIZE - 1) ? a->states[iteration - 1][0] : a->states[iteration - 1][index + 1]);

    return returned_neighbours;
}

void print(automaton* a) {
  (a->_printer)((void*)a);
}
