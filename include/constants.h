#ifndef CONSTANTS_H
#define CONSTANTS_H

#define DEFAULT_ITERATIONS 16 //Default number of iterations
#define DEFAULT_SIZE 32 //Default size of the automaton
#define DEFAULT_RULE 110 //Default rule used if no rule is passed as argument (DEPRECATED)
#define DEFAULT_STATES_NUMBER 2 //Default number of states used in the automaton

#define MIN_STATES 2
#define MAX_STATES 10
#define MIN_SIZE 5
#define MIN_ITERATION 2

#define BUFFER_SIZE 512

#include <stdio.h>
#include <stdlib.h>

struct automaton {
    unsigned char states_number;
    unsigned int size;
    unsigned int iterations;
    unsigned char** states; //The array of all the states of the automaton
    char* rule; //The rule
    void (*_printer)(void* automaton); //Printing function used
};

typedef struct automaton automaton;

extern const unsigned char SYMBOLS[];
extern const char* TABLE[]; //DEPRECATED


#endif
