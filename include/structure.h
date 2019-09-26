#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdbool.h>
#include "constants.h"
#include "converters.h"

automaton* init(unsigned char states_number,
                unsigned char size,
                unsigned char iterations,
                unsigned char starting_position,
                unsigned char* rule,
                void (*_printer)(void*));

void destroy(automaton** a);
void start(automaton* a);

void update_state(automaton* a, size_t iteration);
unsigned char apply_rule(automaton* a, unsigned char* neighbours);

bool compare_state(size_t index, unsigned char* tested_state);
unsigned char* get_neighbours(automaton* a, size_t iteration, size_t index);

void print(automaton* a);

#endif
