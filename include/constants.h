#ifndef CONSTANTS_H
#define CONSTANTS_H

#define ITERATIONS 16 //Number of iterations
#define SIZE 32 //Size of the automaton
#define DEFAULT_RULE 110 //Rule used if no rule is passed as argument
#define STATES_NUMBER 2 //Number of states used in the automaton

#include <stdio.h>
#include <stdlib.h>

struct automaton {
    unsigned char integer_rule; //The rule as integer (Before conversion)
    unsigned char** states; //The array of all the states of the automaton
    unsigned char** table; 
    unsigned char* rule; //The rule as binary (After conversion)
};

typedef struct automaton automaton;

extern const unsigned char SYMBOLS[];
extern const char* TABLE[];


#endif