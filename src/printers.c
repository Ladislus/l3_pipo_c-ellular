/**
 * @file printers.c
 * @author Ladislas WALCAK, Simon DRIEUX
 * @brief Functions used to print (in termianl or file) the automaton
 * @version 0.1
 * @date 2019-10-05
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "printers.h"


/**
 * @brief Default function to print the automaton in the terminal
 * 
 * @param a void* : The automaton pointer
 */
void default_print(void* a) {

  //Convert the automaton from "void*" to "automaton*"
  const automaton* converted_automaton = (automaton*)a;

  //Printing a header for better visibility
  printf("\n\t===========\n\t= RESULTS =\n\t===========\n\n");

  //Printing the automaton information
  printf("Number of states : %hd\n", converted_automaton->states_number); //The nulber of states
  printf("rule : %s\n", converted_automaton->rule);                       //The rule
  printf("Size of the automaton : %d\n", converted_automaton->size);      //The size (width)
  printf("Number of iterations : %d\n", converted_automaton->iterations); //The number of iterations (height)

  //Printing characters one by one
  for(size_t i = 0; i < converted_automaton->iterations; i++) {
      i < 10 ? printf("|%ld | ", i) : printf("|%ld| ", i);                //The index of the line
      //SYMBOLS contains the symbols matching the current state
      for(size_t j = 0; j < (unsigned)(converted_automaton->size - 1); j++) printf("%c", SYMBOLS[converted_automaton->states[i][j]]);
      //Last state of the line is printed separatly to add the "\n"
      printf("%c\n", SYMBOLS[converted_automaton->states[i][converted_automaton->size - 1]]);
  }
  //Printing a line break for better visibility
  printf("\n");
}

/**
 * @brief Default function to print the automaton in a pgm file
 * 
 * @param a void* : The automaton pointer
 */
void default_saver(void* a) {

  //Convert the automaton from "void*" to "automaton*" 
  automaton* converted_automaton = (automaton*)a;

  //Create the struct containing the output file's informations
  pgm* pgm = create_pgm(converted_automaton->size,                //File's width
                        converted_automaton->iterations,          //File's height
                        (converted_automaton->states_number - 1), //File's maximum state
                        converted_automaton->states);             //File's pixels

  //Write the informations into the actual file "output.pgm"
  write_pgm("./output.pgm", pgm); 

  //Destroy the create pgm struct
  destroy_pgm(&pgm);
  pgm = NULL;
}