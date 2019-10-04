#include "menu.h"

bool is_valid_answer(unsigned char answer) {
    return ((answer == 'y' || answer == 'n' || answer == 'Y' || answer == 'N') ? true : false);
}

bool is_yes(unsigned char answer) {
    return ((answer == 'y' || answer == 'Y') ? true : false);
}

automaton* menu() {

    unsigned char from_file = 0, out_method = 0;
    void (*_printer)(void*) = NULL;

    do {
       printf("Output method (1. terminal, 2. pgm file) : ");
       scanf(" %c", &out_method);
       
       if(out_method == '1') _printer = &default_print;
       else if(out_method == '2') _printer = &default_saver;
       
    } while(out_method < '1' || out_method > '2');

    do {
        printf("Import config from file (y/n) : ");
        scanf(" %c", &from_file);
    } while(!is_valid_answer(from_file));

    if(is_yes(from_file)) {

        char file_path[1024];

        printf("Enter path to config file : ");
        scanf(" %s", file_path);

        return init_file(file_path, _printer);
    }
    else {
        unsigned char states_number = 0, size = 0, iteration = 0;

        do {
            printf("Number of states (%d <= X <= %d : ", MIN_STATES, MAX_STATES);
            scanf(" %hhu", &states_number);
        } while(states_number < MIN_STATES || states_number > MAX_STATES);

        do {
            printf("Size (%d <= X <= 255) : ", MIN_SIZE);
            scanf(" %hhu", &size);
        } while(size < MIN_SIZE);

        do {
           printf("Iteration (%d <= X <= 255) : ", MIN_ITERATION);
           scanf(" %hhu", &iteration);
        } while(iteration < MIN_ITERATION);

        char start[BUFFER_SIZE], rule[BUFFER_SIZE];

        do {
            printf("Start (required length %d characters) : ", size);
            scanf(" %s", start);
        } while(strlen(start) != size);
        start[strlen(start)] = '\0';

        do {
           printf("Rule (required length %d characters) : ", (((states_number - 1) * 3) + 1));
           scanf(" %s", rule);
        } while (strlen(rule) != (size_t)(((states_number - 1) * 3) + 1));
        rule[strlen(rule)] = '\0';

        return init(states_number, size, iteration, start, rule, _printer);
    }
}