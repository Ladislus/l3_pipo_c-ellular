#ifndef CONSTANTS_H
#define CONSTANTS_H

#define DEFAULT_ITERATIONS 16 //Default number of iterations
#define DEFAULT_SIZE 32 //Default size of the automaton
#define DEFAULT_RULE 110 //Default rule used if no rule is passed as argument (DEPRECATED)
#define DEFAULT_STATES_NUMBER 2 //Default number of states used in the automaton

#include <stdio.h>
#include <stdlib.h>

struct automaton {
    unsigned char states_number;
    unsigned char size;
    unsigned char iterations;
    // unsigned char integer_rule; //The rule as integer, before conversion (DEPRECATED)
    unsigned char** states; //The array of all the states of the automaton
    char* rule; //The rule
    void (*_printer)(void* automaton); //Printing function used
};

typedef struct automaton automaton;

extern const unsigned char SYMBOLS[];
extern const char* TABLE[]; //DEPRECATED


#endif
