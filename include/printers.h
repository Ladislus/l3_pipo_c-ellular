/**
 * @file printers.h
 * @author Ladislas WALCAK (ladislas.walcak@etu.univ-orleans.fr), Simon DRIEUX (simon.drieux@etu.univ-orleans.fr)
 * @brief HEADER - Functions used to print (in termianl or file) the automaton
 * @version 0.1
 * @date 2019-10-05
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef PRINTERS_H
#define PRINTERS_H

#include "constants.h"  //Require the automaton struct
#include "pgm.h"        //Require pgm manipulation functions

/**
 * @brief Default function to print the automaton in the terminal
 * 
 * @param a void* : The automaton pointer
 */
void default_print(void* a);

/**
 * @brief Default function to print the automaton in a pgm file
 * 
 * @param a void* : The automaton pointer
 */
void default_saver(void* a);

#endif
