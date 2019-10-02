#include "structure.h"

automaton* init(unsigned char states_number,
                unsigned char size,
                unsigned char iterations,
                unsigned char starting_position,
                char* rule,
                void (*_printer)(void*)) {

    assert(starting_position <= (size - 1));
    assert(states_number <= 10);
    assert(strlen(rule) <= (unsigned)(((states_number - 1) * 3) + 1));
    for(size_t i = 0; i < strlen(rule); i++) assert(rule[i] >= '0' && rule[i] <= '9');

    automaton* returned_automaton = (automaton*)malloc(sizeof(automaton));

    returned_automaton->states_number = states_number;
    returned_automaton->size = size;
    returned_automaton->iterations = iterations;
    returned_automaton->rule = (unsigned char*)rule;
    returned_automaton->_printer = _printer;

    /* DEPRECATED
    returned_automaton->integer_rule = rule;
    returned_automaton->rule = convert_rule_binary(rule);
    */

    returned_automaton->states = (unsigned char**)malloc(returned_automaton->iterations * sizeof(unsigned char*));
    for(size_t i = 0; i < returned_automaton->iterations; i++) {
        returned_automaton->states[i] = (unsigned char*)calloc(returned_automaton->size, sizeof(unsigned char));
    }
    returned_automaton->states[0][starting_position] = 1;

    return returned_automaton;
}

automaton* init_file(FILE* file, void (* _printer)(void*)) {
  exit(EXIT_SUCCESS);
}

void destroy(automaton** a) {
    for(size_t i = 0; i < (*a)->iterations; i++) {
        free((*a)->states[i]);
        (*a)->states[i] = NULL;
    }
    free((*a)->states);
    (*a)->states = NULL;

    free(*a);
}

void start(automaton* a) {
    for(size_t i = 1; i < a->iterations; i++) {
        update_state(a, i);
    }
    print(a);
}

//DEPRECATED
unsigned char apply_rule(automaton* a, unsigned char* neighbours) {
    for(size_t i = 0; i < 8; i++) {
        if(compare_state(i, neighbours)) return (a->rule[i] - '0');
    }
    fprintf(stderr, "No matching rule found, exiting ...\n");
    exit(EXIT_FAILURE);
}

//DEPRECATED
bool compare_state(size_t index, unsigned char* tested_state) {
    return ((TABLE[index][0] - '0') == tested_state[0] && (TABLE[index][1] - '0') == tested_state[1] && (TABLE[index][2] - '0') == tested_state[2]);
}

void update_state(automaton* a, size_t iteration) {
    for(size_t i = 0; i < a->size; i++) {
      /* DEPRECATED
      unsigned char* neighbours = get_neighbours(a, iteration, i);
      a->states[iteration][i] = apply_rule(a, neighbours);
      free(neighbours);
      neighbours = NULL;
      */
      unsigned char new_char = a->rule[somme(a, iteration, i)] - '0';
      printf("new_char : %c\n", new_char - '0');
      a->states[iteration][i] = new_char;
    }
}

unsigned char somme(automaton* a, size_t iteration, size_t index) {
  unsigned char returned_value = 0;

  // returned_value += (!index ? a->states[iteration - 1][a->size - 1] - '0' : a->states[iteration - 1][index - 1] - '0');
  // returned_value += (a->states[iteration - 1][index] - '0');
  // returned_value += (index == (unsigned char)(a->size - 1) ? a->states[iteration - 1][0] - '0' : a->states[iteration - 1][index + 1] - '0');

    printf("returned_value : %d\n", returned_value);
    unsigned char tmp_value = (!index ? a->states[iteration - 1][a->size - 1] : a->states[iteration - 1][index - 1]);
    printf("tmp_value 1 (char) : %c\n", tmp_value);
    printf("tmp_value 1 : %d\n", tmp_value);
    returned_value += tmp_value;
    printf("returned_value (After) : %d\n-----------------\n", returned_value);

    printf("returned_value : %d\n", returned_value);
    tmp_value = (a->states[iteration - 1][index]);
    printf("tmp_value 2 (char) : %c\n", tmp_value);
    printf("tmp_value 2 : %d\n", tmp_value);
    returned_value += tmp_value;
    printf("returned_value (After) : %d\n-----------------\n", returned_value);

    printf("returned_value : %d\n", returned_value);
    tmp_value = (index == (unsigned char)(a->size - 1) ? a->states[iteration - 1][0] : a->states[iteration - 1][index + 1]);
    printf("tmp_value 3 (char) : %c\n", tmp_value);
    printf("tmp_value 3 : %d\n", tmp_value);
    returned_value += tmp_value;
    printf("returned_value (After) : %d\n-----------------\n", returned_value);

  printf("somme : %d\n\n", returned_value);

  return returned_value;
}

unsigned char* get_neighbours(automaton* a, size_t iteration, size_t index) {
    unsigned char* returned_neighbours = (unsigned char*)malloc(3 * sizeof(unsigned char));

    returned_neighbours[0] = (!index ? a->states[iteration - 1][a->size - 1] : a->states[iteration - 1][index - 1]);
    returned_neighbours[1] = a->states[iteration - 1][index];
    returned_neighbours[2] = (index == (unsigned)(a->size - 1) ? a->states[iteration - 1][0] : a->states[iteration - 1][index + 1]);

    return returned_neighbours;
}

void print(automaton* a) {
  (a->_printer)((void*)a);
}
