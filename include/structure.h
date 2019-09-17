#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdlib.h>
#include "convert.h"
#include "printing.h"

//Nombres d'itérations maximales
#define ITERATIONS 16
//Taille de la grille
#define SIZE 32

struct grille {
  unsigned char rule_i;
  int* rule_b;
  int* values;
};

typedef struct grille grille;

/*!
   \brief "Initialisation de la structure"
   \param "Rien"
   \return "Pointeur vers la nouvelle grille"
*/
grille* init(unsigned char rule);

/*!
   \brief "Libère la mémoire allouée a la grille"
   \param "L'adresse de la grille"
*/
void destroy(grille** g);

/*!
   \brief "Affiche les voisins, état 1 ou 0"
   \param "Une grille g contenant les cellules et un index du tableau"
   \return "[voisin1, voisin2]"
*/
int* get_neighbors(grille* const g, size_t index);

/*!
   \brief "Retourne le nouvel état selon les voisins"
   \param "Une grille contenant la règle et les cellules"
*/
void new_state(grille* g);

/*!
   \brief "Utilisé en boucle pour remplacer le tableau par le nouveau tableau"
   \param "Une grille"
*/
void play(grille* g);

#endif
