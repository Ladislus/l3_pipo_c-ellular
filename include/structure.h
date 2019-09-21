#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdbool.h>
#include "constants.h"
#include "converters.h"
#include "printers.h"

automaton* init(unsigned char rule);
void destroy(automaton** a);
void start(automaton* a);
void update_state(automaton* a, size_t iteration);
bool compare_state(automaton* a, size_t index, unsigned char* tested_state);
unsigned char* get_neighbours(automaton* a, size_t iteration, size_t index);
unsigned char apply_rule(automaton* a, unsigned char* neighbours);

#endif