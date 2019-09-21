#include "converters.h"

unsigned char* convert_rule_binary(unsigned char rule) {
    //Converting rule to an integer representing rule's binary value
    unsigned int binary_integer = integer_to_binary_integer((unsigned int)rule);

    //Allocating 
    unsigned char* binary_char = (unsigned char*)malloc(9 * sizeof(unsigned char));

    //Converting the integer into a temporary string
    char tmp[8];
    sprintf(tmp, "%d", binary_integer);

    //Getting the number of zeros to add to have 8 characters
    unsigned char missing_zeros = 8 - strlen(tmp);

    for(size_t i = 0; i < 8; i++) {
        //Add the missing zeros
        if(i < missing_zeros) binary_char[i] = '0';
        //Store the integer into the string
        else binary_char[i] = tmp[i - missing_zeros];
    }
    //Adding the NUL terminator at the end of the string
    binary_char[8] = '\0';

    return binary_char;
}

unsigned int integer_to_binary_integer(unsigned int rule) {
    if(rule <= 1) return rule;
    return ((rule % 2) + 10 * integer_to_binary_integer(rule / 2));
}