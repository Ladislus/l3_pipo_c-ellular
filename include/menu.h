#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdbool.h>
#include "printers.h"
#include "structure.h"

bool is_valid_answer(unsigned char answer);
bool is_yes(unsigned char answer);

automaton* menu();

#endif