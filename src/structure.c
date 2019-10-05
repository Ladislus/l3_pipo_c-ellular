/**
 * @file structure.c
 * @author Ladislas WALCAK (ladislas.walcak@etu.univ-orleans.fr), Simon DRIEUX (simon.drieux@etu.univ-orleans.fr)
 * @brief Functions used to manipulate automaton struct
 * @version 0.1
 * @date 2019-10-05
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "structure.h"

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
                void (*_printer)(void*)) {

    //Check if values match minimums
    assert(states_number >= MIN_STATES);
    assert(size >= MIN_SIZE);
    assert(iterations >= MIN_ITERATION);

    //Check if "start" and "rule" have valid sizes
    assert(strlen(start) == size);
    assert(strlen(rule) <= (size_t)(((states_number - 1) * 3) + 1));

    //Check if rule contains only valid numbers
    for(size_t i = 0; i < strlen(rule); i++) assert(rule[i] >= '0' && rule[i] <= ((states_number - 1) + '0'));

    //Allocate space for the created automaton
    automaton* returned_automaton = (automaton*)malloc(sizeof(automaton));

    //Assign values to the automaton 
    returned_automaton->states_number = states_number;  //The number of states
    returned_automaton->size = size;                    //The size (width)
    returned_automaton->iterations = iterations;        //The number of iteration (height)
    returned_automaton->_printer = _printer;            //The function used to print the automaton

    //Allocate space for the array constaining the rule
    returned_automaton->rule = (char*)malloc(sizeof(char) * (strlen(rule) + 1));
    //Copying the rule into the automaton (strcpy prevent the loss of the rule on parameter destruction)
    strcpy(returned_automaton->rule, rule);

    //Allocate space for the matrix of pixels
    returned_automaton->states = (unsigned char**)malloc(returned_automaton->iterations * sizeof(unsigned char*));
    
    //Allocate space for the first line of the matrix given by the user
    returned_automaton->states[0] = (unsigned char*)malloc(sizeof(unsigned char) * returned_automaton->size);
    for(size_t i = 0; i < returned_automaton->size; i++) {
        //Check if the current character of the first iteration is valid
        assert(start[i] >= '0' && start[i] < (states_number + '0'));
        //Store the value in the pixels matrix
        returned_automaton->states[0][i] = (start[i] - '0');
    }

    //Allocate space for the others iteration of the automaton
    for(size_t i = 1; i < returned_automaton->iterations; i++) {
        returned_automaton->states[i] = (unsigned char*)calloc(returned_automaton->size, sizeof(unsigned char));
    }

    //Return the pointer of the created automaton
    return returned_automaton;
}

/**
 * @brief Function to create an automaton using a config file (.txt)
 * 
 * @param file_path char* : The filepath to the config file
 * @param _printer void* : The pointer of the print function used
 * @return automaton* The pointer of the created automaton
 */
automaton* init_file(char* file_path, void (* _printer)(void*)) {

    //Open the file from which config is read
    FILE* file = fopen(file_path, "r");
    //If the file couldn't be opened, exit the function with errors
    if(file == NULL) exit(EXIT_FAILURE);

    //Declare variables to store the data read from the file
    unsigned char states_number;        //The number of states
    unsigned int size, iteration;       //The size (width) and number of iterations (height)

    //Read number of states
    fscanf(file, "States=%hhu", &states_number);
    fseek(file, +1, SEEK_CUR);

    //Read size (width)
    fscanf(file, "Size=%u", &size);
    fseek(file, +1, SEEK_CUR);

    //Read number of iterations (height)
    fscanf(file, "Iteration=%u", &iteration);
    fseek(file, +1, SEEK_CUR);

    /*
    Declaration of a buffer for the first iteration
    The buffer is twice the needed size to prevent side effect
    If the given value for Start dosen't have the right size,
    an assert will stop the program at the beginning of init()

    TODO : Improve read method to prevent side effect
    */
    char* start = (char*)malloc(sizeof(char) * (2 * size));

    //Read first iteration
    fscanf(file, "Start=%s", start);
    fseek(file, +1, SEEK_CUR);

    /*
    Declaration of a buffer for the rule
    Rule maximum size is 11 (10 characters + '\0')
    The buffer is bigger to prevent side effect
    If the given value for rule dosen't have the right size,
    an assert will stop the program at the beginning of init()

    TODO : Improve read method to prevent side effect
    */
    char rule[BUFFER_SIZE];

    //Read the rule
    fscanf(file, "Rule=%s", rule);

    //Close the file
    fclose(file);
    file = NULL;

    //Store the created automaton (Start must be freed before returning the automaton)
    automaton* returned_automaton = init(states_number,
                                    size,
                                    iteration,
                                    start,
                                    rule,
                                    _printer);

    free(start);
    start = NULL;                               

    //Return the created automaton
    return returned_automaton;
}

/**
 * @brief Function to destroy the automaton struct
 * 
 * @param a automaton** : The pointer to the automaton
 */
void destroy(automaton** a) {

    //Free each line of the pixels matrix
    for(size_t i = 0; i < (*a)->iterations; i++) {
        free((*a)->states[i]);
        (*a)->states[i] = NULL;
    }

    //Free the pixels matrix
    free((*a)->states);
    (*a)->states = NULL;

    //Free the array containing rule
    free((*a)->rule);
    (*a)->rule = NULL;

    //Free the automaton struct
    free(*a);
    (*a) = NULL;
}

/**
 * @brief The function to start the automaton and compute all the iterations of the automaton
 * 
 * @param a automaton* : The pointer of the automaton
 */
void start(automaton* a) {

    //Compute all the iterations of the automaton
    for(size_t i = 1; i < a->iterations; i++) {
        update_state(a, i);
    }

    //Print the automaton
    print(a);
}

/**
 * @brief Function to compute the current iteration
 * 
 * @param a automaton* : The pointer of the automaton
 * @param iteration size_t : The index of the iteration to compute
 */
void update_state(automaton* a, size_t iteration) {

    //For each state of the current iteration
    for(size_t i = 0; i < a->size; i++)
        //update the value of the current state        
        a->states[iteration][i] = (a->rule[somme(a, iteration, i)] - '0');
}

/**
 * @brief Function to get the index of the new value of the current state
 * 
 * @param a automaton* : The pointer of the automaton
 * @param iteration size_t : The index of the iteration
 * @param index size_t : The index of the current state
 * @return unsigned char The new value of the current state
 */
unsigned char somme(automaton* a, size_t iteration, size_t index) {

    //Initialise a variable for the sum
    unsigned char returned_value = 0;

    //Add the value of each neighboor to the sum
    returned_value += (!index ? a->states[iteration - 1][a->size - 1] : a->states[iteration - 1][index - 1]);
    returned_value += (a->states[iteration - 1][index]);
    returned_value += (index == (unsigned int)(a->size - 1) ? a->states[iteration - 1][0] : a->states[iteration - 1][index + 1]);

    //Return the sum
    return returned_value;
}

/**
 * @brief Function to print the automaton
 * 
 * @param a automaton* : The pointer of the automaton
 */
void print(automaton* a) {
    
    //Print the autoamton
    (a->_printer)((void*)a);
}
