/**
 * @file automaton.c
 * @author Ladislas WALCAK (ladislas.walcak@etu.univ-orleans.fr), Simon DRIEUX (simon.drieux@etu.univ-orleans.fr)
 * @brief Main file of the executable file
 * @version 0.1
 * @date 2019-10-05
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "menu.h"

/**
 * @brief Main function
 * 
 * @param argc int : (UNUSED) Number of parameters 
 * @param argv char** : (UNUSED) Array of the parameters
 * @return int The exit status
 */
int main(int argc, char** argv) {

    //Declare a pointer for the automaton
    automaton* a = NULL;

    //Launch the menu and assign an automaton to variable "a"
    a = menu();

    //Start the automaton
    start(a);
    //Once finished, destroy the automaton
    destroy(&a);

    //Exit the program
    return EXIT_SUCCESS;
}
