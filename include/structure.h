/**
 * @file structure.h
 * @author Ladislas WALCAK (ladislas.walcak@etu.univ-orleans.fr), Simon DRIEUX (simon.drieux@etu.univ-orleans.fr)
 * @brief HEADER - Functions used to manipulate automaton struct
 * @version 0.1
 * @date 2019-10-05
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "constants.h"

/**
 * @brief Function to create an automaton
 * 
 * @param states_number unsigned char : The number of states of the automaton
 * @param size  unsigned int : The size (width) of the automaton
 * @param iterations  unsigned int : The number of iterations (height) of the automaton
 * @param start char* : The first iteration of the automaton
 * @param rule char* : The rule to get the next iteration of the automaton
 * @param _printer  void*: The pointer of the printing function
 * @return automaton* The pointer of the created automaton
 */
automaton* init(unsigned char states_number,
                unsigned int size,
                unsigned int iterations,
                char* start,
                char* rule,
                void (*_printer)(void*));

/**
 * @brief Function to create an automaton using a config file (.txt)
 * 
 * @param file_path char* : The filepath to the config file
 * @param _printer void* : The pointer of the print function used
 * @return automaton* The pointer of the created automaton
 */
automaton* init_file(char* file_path, void (* _printer)(void*));

/**
 * @brief Function to destroy the automaton struct
 * 
 * @param a automaton** : The pointer to the automaton
 */
void destroy(automaton** a);

/**
 * @brief The function to start the automaton and compute all the iterations of the automaton
 * 
 * @param a automaton* : The pointer of the automaton
 */
void start(automaton* a);

/**
 * @brief Function to compute the current iteration
 * 
 * @param a automaton* : The pointer of the automaton
 * @param iteration size_t : The index of the iteration to compute
 */
void update_state(automaton* a, size_t iteration);

/**
 * @brief Function to get the index of the new value of the current state
 * 
 * @param a automaton* : The pointer of the automaton
 * @param iteration size_t : The index of the iteration
 * @param index size_t : The index of the current state
 * @return unsigned char The new value of the current state
 */
unsigned char somme(automaton* a, size_t iteration, size_t index);

/**
 * @brief Function to print the automaton
 * 
 * @param a automaton* : The pointer of the automaton
 */
void print(automaton* a);

#endif
