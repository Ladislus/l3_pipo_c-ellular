#include "printers.h"

void default_print(void* a) {
  const automaton* converted_automaton = (automaton*)a;
  printf("\n\t===========\n\t= RESULTS =\n\t===========\n\n");
  printf("Number of states : %hd\n", converted_automaton->states_number);
  printf("rule : %s\n", converted_automaton->rule);
  printf("Size of the automaton : %d\n", converted_automaton->size);
  printf("Number of iterations : %d\n", converted_automaton->iterations);
  for(size_t i = 0; i < converted_automaton->iterations; i++) {
      i < 10 ? printf("|%ld | ", i) : printf("|%ld| ", i);
      for(size_t j = 0; j < (unsigned)(converted_automaton->size - 1); j++) printf("%c", SYMBOLS[converted_automaton->states[i][j]]);
      printf("%c\n", SYMBOLS[converted_automaton->states[i][converted_automaton->size - 1]]);
  }
  printf("\n");
}

void default_saver(void* a) {
  automaton* converted_automaton = (automaton*)a;

  pgm* pgm = create_pgm(converted_automaton->size,
                        converted_automaton->iterations,
                        (converted_automaton->states_number - 1),
                        converted_automaton->states);

  write_pgm("./output.pgm", pgm);

  destroy_pgm(&pgm);
  pgm = NULL;
}