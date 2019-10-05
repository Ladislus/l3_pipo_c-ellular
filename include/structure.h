#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdbool.h>
#include "constants.h"
#include "assert.h"

automaton* init(unsigned char states_number,
                unsigned int size,
                unsigned int iterations,
                char* start,
                char* rule,
                void (*_printer)(void*));
automaton* init_file(char* file_path, void (* _printer)(void*));

void destroy(automaton** a);
void start(automaton* a);

void update_state(automaton* a, size_t iteration);
unsigned char apply_rule(automaton* a, unsigned char* neighbours);

bool compare_state(size_t index, unsigned char* tested_state); //DEPRECATED
unsigned char* get_neighbours(automaton* a, size_t iteration, size_t index); //DEPRECATED
unsigned char somme(automaton* a, size_t iteration, size_t index);

void print(automaton* a);

#endif
