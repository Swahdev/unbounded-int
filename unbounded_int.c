//
// Created by Charles Chikhani on 28/03/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include "main.h"

int main() {
    unbounded_int unboundedInt1 = ll2unbounded_int(-7653891);
    unbounded_int unboundedInt2 = ll2unbounded_int(-1001);
    unbounded_int unboundedInt3 = ll2unbounded_int(-2001);
    unbounded_int unboundedInt4 = unbounded_int_produit(unboundedInt2, unboundedInt3);
    affiche(unboundedInt4);
    //char *str1 = unbounded_int2string(unboundedInt1);
    //printf("%s", str1);
    return 0;
}

unbounded_int ll2unbounded_int(long long i) {
    unbounded_int un1;
    if (i < 0) {
        un1.signe = '-';
    } else if (i == 0) {
        un1.signe = '+';
        un1.len = 1;
        chiffre *zero = malloc(sizeof(chiffre));
        assert(zero);
        zero->c = '0';
        zero->suivant = zero;
        zero->precedent = zero;
        un1.premier = zero;
        un1.dernier = zero;
        return un1;
    } else
        un1.signe = '+';

    //on converti notre long long en char

    //un1.len = floorl(log10l(llabs(i))) + 1;
    un1.len = taillell(i);
    char char1[un1.len];
    sprintf(char1, "%lld", llabs(i));

    //On alloc nos chiffres

    chiffre *nombre = malloc(un1.len * sizeof(chiffre));
    assert(nombre);
    //on remplie le PREMIER
    un1.premier = nombre;
    nombre->c = char1[0];
    nombre->precedent = NULL;
    nombre->suivant = (nombre + 1);
    nombre++;
    for (int j = 1; j < un1.len - 1; j++) {
        nombre->c = char1[j];
        //printf("%c", nombre->c);
        nombre->suivant = (nombre + 1);
        nombre->precedent = (nombre - 1);
        nombre++;
    }
    nombre->c = char1[un1.len - 1];
    nombre->suivant = NULL;
    nombre->precedent = (nombre - 1);
    un1.dernier = nombre;
    return un1;
}

int taillell(long long i) {
    int len = 0;
    long long m = 0;
    long long modul = 10;
    while (m < llabs(i)) {
        m = llabs(i) % modul;
        modul *= 10;
        len++;
    }
    return len;
}

void freeUnbounded(unbounded_int *a) {
    chiffre *indice;
    chiffre *tmp;
    indice = a->premier;
    while (indice->suivant != NULL) {
        tmp = indice++;
        free(indice);
        indice = tmp;
    }
    free(a);
}

char *unbounded_int2string(unbounded_int i) {
    char *a = malloc(sizeof(char) * (i.len + 2));
    assert(a);
    a[0] = i.signe;
    chiffre *tmp = i.premier;
    int o = 1;
    while (tmp->suivant != NULL) {
        a[o] = tmp->c;
        o++;
        tmp = tmp->suivant;
    }
    a[o] = tmp->c;
    a[o + 1] = '\0';
    return a;
}

int unbounded_int_cmp_ll(unbounded_int a, long long b) {
    unbounded_int d = ll2unbounded_int(b);
    return unbounded_int_cmp_unbounded_int(a, d);
}

unbounded_int unbounded_int_somme(unbounded_int a, unbounded_int b) {
    char *str1 = unbounded_int2string(a);
    char *str2 = unbounded_int2string(b);
    long long somme = atoll(str2) + atoll(str1);
    unbounded_int unboundedInt = ll2unbounded_int(somme);
    return unboundedInt;
}

unbounded_int unbounded_int_difference(unbounded_int a, unbounded_int b) {
    char *str1 = unbounded_int2string(a);
    char *str2 = unbounded_int2string(b);
    long long diff = atoll(str1) - atoll(str2);
    unbounded_int unboundedInt = ll2unbounded_int(diff);
    return unboundedInt;
}

void affiche(unbounded_int a) {
    chiffre *chiffre1 = a.premier;
    printf("%c", a.signe);
    if (a.len == 1) {
        printf("%c", a.premier->c);
        printf("\n");
    } else {
        while (chiffre1->suivant != NULL) {
            printf("%c", chiffre1->c);
            chiffre1 = chiffre1->suivant;
        }
        printf("%c", chiffre1->c);
        printf("\n");
    }
}

unbounded_int unbounded_int_produit(unbounded_int a, unbounded_int b) {
    char *str1 = unbounded_int2string(a);
    char *str2 = unbounded_int2string(b);
    long long produit = atoll(str2) * atoll(str1);
    unbounded_int unboundedInt = ll2unbounded_int(produit);
    return unboundedInt;
}