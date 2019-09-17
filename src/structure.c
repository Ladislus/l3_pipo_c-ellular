#include "structure.h"

grille* init(unsigned char rule) {
  //Allocation de la mémoire de la structure retournée
  grille* returned_grille = (grille*)malloc(sizeof(grille));

  returned_grille->rule_i = rule;
  returned_grille->rule_b = rule_to_binary(rule);
  returned_grille->values = (int*)calloc(SIZE, sizeof(int));

  return returned_grille;
}

void destroy(grille** g) {

  free((*g)->values);
  (*g)->values = NULL;

  free(*g);
}

int* get_neighbors(grille* const g, size_t index) {

  int* returned_neighbors = (int*)malloc(sizeof(int) * 2);

  returned_neighbors[0] = (!index ? g->values[SIZE -1] : g->values[index - 1]);
  returned_neighbors[1] = g->values[index];
  returned_neighbors[2] = ((index == (SIZE - 1)) ? g->values[0] : g->values[index + 1]);

  return returned_neighbors;
}

void new_state(grille* g) {
  int* res_temp = (int*)calloc(SIZE, sizeof(int));
  for (size_t i = 0; i < SIZE; i++) {
    int* temp = get_neighbors(g, i);
    if (temp[0]==1 && temp[1]==1 && temp[2]==1) {
      res_temp[i] = g->rule_b[0];
    }
    if (temp[0]==1 && temp[1]==1 && temp[2]==0) {
      res_temp[i] = g->rule_b[1];
    }
    if (temp[0]==1 && temp[1]==0 && temp[2]==1) {
      res_temp[i] = g->rule_b[2];
    }
    if (temp[0]==1 && temp[1]==0 && temp[2]==0) {
      res_temp[i] = g->rule_b[3];
    }
    if (temp[0]==0 && temp[1]==1 && temp[2]==1) {
      res_temp[i] = g->rule_b[4];
    }
    if (temp[0]==0 && temp[1]==1 && temp[2]==0) {
      res_temp[i] = g->rule_b[5];
    }
    if (temp[0]==0 && temp[1]==0 && temp[2]==1) {
      res_temp[i] = g->rule_b[6];
    }
    if (temp[0]==0 && temp[1]==0 && temp[2]==0) {
      res_temp[i] = g->rule_b[7];
    }
    else{
      return;
    }
  }
  g->values = res_temp;
  printf("%ls\n", g->values);
  return NULL;
}

void play(grille* g) {
  for(size_t i = 0; i < ITERATIONS; i++) {

  }
}
