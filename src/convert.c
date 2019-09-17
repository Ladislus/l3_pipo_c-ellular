#include "convert.h"

unsigned int int_to_binary(unsigned char rule) {
  char str[8];
  sprintf(str, "%d", rule);
  if(rule <= 1) return rule;
  return (rule % 2) + 10 * int_to_binary(rule / 2);
}

int* rule_to_binary(unsigned char rule) {
  unsigned int binary_i = int_to_binary(rule);
  return NULL;
}
