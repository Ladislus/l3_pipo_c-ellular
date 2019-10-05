/**
 * @file menu.h
 * @author Ladislas WALCAK, Simon DRIEUX
 * @brief HEADER - Functions used to print the menu
 * @version 0.1
 * @date 2019-10-05
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef MENU_H
#define MENU_H

#include "printers.h"   //Require the print functions 
#include "structure.h"  //Require constants.h, automaton's initialisation functions

/**
 * @brief Function to check if the character is a valid answer
 * 
 * @param answer unsigned char : The user's answer
 * @return true if the answer is a valid character
 * @return false if the answer is not a valid character
 */
bool is_valid_answer(unsigned char answer);

/**
 * @brief Function to check if the answer is yes
 * 
 * @param answer unsigned char : The user's answer
 * @return true if answer is yes
 * @return false if answer is false
 */
bool is_yes(unsigned char answer);

/**
 * @brief Function to launch the menu, and create the corresponding automaton
 * 
 * @return automaton* The automaton created according to user's answers
 */
automaton* menu();

#endif