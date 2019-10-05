/**
 * @file constants.h
 * @author Ladislas WALCAK (ladislas.walcak@etu.univ-orleans.fr), Simon DRIEUX (simon.drieux@etu.univ-orleans.fr)
 * @brief Constants, structs and includes shared with every other files of the project
 * @version 0.1
 * @date 2019-10-05
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#define MIN_STATES 2                    //Minimum nuber of states of the automaton
#define MAX_STATES 10                   //Maximum number of states of the automaton
#define MIN_SIZE 5                      //Minimum size (width) of the automaton
#define MIN_ITERATION 2                 //Minimum number of iterations (height) of the automaton

#define BUFFER_SIZE 512                 //Default buffer size

#include <stdio.h>                      //I/O functions
#include <stdlib.h>                     //Standard functions
#include <string.h>                     //Strings functions
#include <stdbool.h>                    //Booleans
#include <assert.h>                     //Asserts

struct automaton {
    unsigned char states_number;        //Number of states of the automaton
    unsigned int size;                  //Size (width) of the automaton
    unsigned int iterations;            //Number of iterations (height) of the automaton
    unsigned char** states;             //The states of the automaton for each iteration
    char* rule;                         //The rule to get the next automaton iteration
    void (*_printer)(void* automaton);  //Printing function used for the automaton
};

struct pgm {
     unsigned int width;                //The file width
     unsigned int height;               //The file height
     unsigned char max_value;           //The maximum value in the pixels
     unsigned char** image;             //The array of pixels
};

typedef struct automaton automaton;     //Automaton alias
typedef struct pgm pgm;                 //Pgm alias


extern const unsigned char SYMBOLS[];   //Array of symbols used to represent the states

#endif
