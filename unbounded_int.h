//
// Created by Charles Chikhani on 30/03/2022.
//

#ifndef PROJET_DE_C_UNBOUNDED_INT_H
#define PROJET_DE_C_UNBOUNDED_INT_H

#include <stdio.h>
#include <stdlib.h>

#endif //PROJET_DE_C_UNBOUNDED_INT_H

typedef struct chiffre {
    struct chiffre *suivant;
    char c;
    struct chiffre *precedent;
} chiffre;

typedef struct unbounded_int {
    char signe; /* soit ’+’ soit ’-’ */
    size_t len; /* longueur de la liste */
    chiffre *premier; /* pointeur vers le premier élément de la liste*/
    chiffre *dernier; /*pointeur vers le dernier élément de la liste*/
} unbounded_int;

void freeUnbounded(unbounded_int *a);

unbounded_int ll2unbounded_int(long long i);

char *unbounded_int2string(unbounded_int i);

chiffre *newChiffre(char c, chiffre *precedent, chiffre *suivant);

int taillell(long long i);

int unbounded_int_cmp_ll(unbounded_int a, long long b);

int unbounded_int_cmp_unbounded_int(unbounded_int a, unbounded_int b);

unbounded_int unbounded_int_somme(unbounded_int a, unbounded_int b);

unbounded_int unbounded_int_difference( unbounded_int a, unbounded_int b);

void affiche(unbounded_int a);

unbounded_int unbounded_int_produit( unbounded_int a, unbounded_int b);