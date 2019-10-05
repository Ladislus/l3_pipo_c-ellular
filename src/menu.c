/**
 * @file menu.c
 * @author Ladislas WALCAK (ladislas.walcak@etu.univ-orleans.fr), Simon DRIEUX (simon.drieux@etu.univ-orleans.fr)
 * @brief Functions used to print the menu
 * @version 0.1
 * @date 2019-10-05
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "menu.h"

/**
 * @brief Function to check if the character is a valid answer
 * 
 * @param answer unsigned char : The user's answer
 * @return true if the answer is a valid character
 * @return false if the answer is not a valid character
 */
bool is_valid_answer(unsigned char answer) {
    return ((answer == 'y' || answer == 'n' || answer == 'Y' || answer == 'N') ? true : false);
}

/**
 * @brief Function to check if the answer is yes
 * 
 * @param answer unsigned char : The user's answer
 * @return true if answer is yes
 * @return false if answer is false
 */
bool is_yes(unsigned char answer) {
    return ((answer == 'y' || answer == 'Y') ? true : false);
}

/**
 * @brief Function to launch the menu, and create the corresponding automaton
 * 
 * @return automaton* The automaton created according to user's answers
 */
automaton* menu() {

    //Initializing user's answers with invalid characters (no default)
    unsigned char from_file = 0, out_method = 0;
    //Declaration of the print function
    void (*_printer)(void*) = NULL;

    //Ask user the print function (Termianl or File)
    do {
       printf("Output method (1. terminal, 2. pgm file) : ");
       scanf(" %c", &out_method);
       
       //Assignation of the corresponding print function
       if(out_method == '1') _printer = &default_print;
       else if(out_method == '2') _printer = &default_saver;
       
    } while(out_method < '1' || out_method > '2');

    //Ask user wether to manually enter the configuration, or use a file
    do {
        printf("Import config from file (y/n) : ");
        scanf(" %c", &from_file);
    } while(!is_valid_answer(from_file));

    //Configuration file
    if(is_yes(from_file)) {

        //Buffer to store the path to the configuration file (.txt file)
        char file_path[BUFFER_SIZE];

        printf("Enter path to config file : ");
        scanf(" %s", file_path);

        //Return the pointer of the created automaton
        return init_file(file_path, _printer);
    }
    //Manual
    else {

        unsigned char states_number = 0;        //Number of states
        unsigned int size = 0, iteration = 0;   //Automaton size (width) and number of iterations (height)

        //Ask number of states (between MIN_STATES and MAX_STATES)
        do {
            printf("Number of states (%d <= X <= %d : ", MIN_STATES, MAX_STATES);
            scanf(" %hhu", &states_number);
        } while(states_number < MIN_STATES || states_number > MAX_STATES);

        //Ask automaton's size (width) (between MIN_SIZE and the maximum value of unsigned int)
        do {
            printf("Size (%d <= X <= 65535) : ", MIN_SIZE);
            scanf(" %u", &size);
        } while(size < MIN_SIZE);

        //ask automaton's number of iterations (heigh) (between MIN_ITERATION and the maximum value of unsigned int)
        do {
           printf("Iteration (%d <= X <= 65535) : ", MIN_ITERATION);
           scanf(" %u", &iteration);
        } while(iteration < MIN_ITERATION);

        /*
        Declaration of a buffer for the first iteration
        The buffer is twice the needed size to prevent side effect
        If the given value for Start dosen't have the right size,
        an assert will stop the program at the beginning of init()

        TODO : Improve read method to prevent side effect or errors
        */
        char* start = (char*)malloc(sizeof(char) * (2 * size));

        //Ask automaton's starting state (start's size depends on the automaton's)
        do {
            printf("Start (required length %d characters) : ", size);
            scanf(" %s", start);
        } while(strlen(start) != size);

        /*
        Declaration of a buffer for the rule
        Rule maximum size is 11 (10 characters + '\0')
        The buffer is bigger to prevent side effect
        If the given value for rule dosen't have the right size,
        an assert will stop the program at the beginning of init()

        TODO : Improve read method to prevent side effect or errors
        */
        char rule[BUFFER_SIZE];

        //Ask automaton's rule (The rule's size depends on the number of states)
        do {
           printf("Rule (required length %d characters) : ", (((states_number - 1) * 3) + 1));
           scanf(" %s", rule);
        } while (strlen(rule) != (size_t)(((states_number - 1) * 3) + 1));
        rule[strlen(rule)] = '\0';

        //Store the created automaton (Start must be freed before returning the automaton)
        automaton* returned_automaton = init(states_number, size, iteration, start, rule, _printer);

        //Free the string containing the first iteration
        free(start);
        start = NULL;

        //Return the created automaton
        return returned_automaton;
    }
}