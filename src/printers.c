#include "printers.h"

void default_print(void* a) {
  automaton* converted_automaton = (automaton*)a;
  printf("\nRule : %d\n", converted_automaton->integer_rule);
  printf("Translated rule : %s\n", converted_automaton->rule);
  printf("Size of the automaton : %d\n", a->size);
  printf("Number of iterations : %d\n", a->iterations);
  for(size_t i = 0; i < a->iterations; i++) {
      i < 10 ? printf("|%ld | ", i) : printf("|%ld| ", i);
      for(size_t j = 1; j < (a->size - 1); j++) printf("%c", SYMBOLS[converted_automaton->states[i][j]]);
      printf("%c\n", SYMBOLS[converted_automaton->states[i][a->size - 1]]);
  }
  printf("\n");
}
