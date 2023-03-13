//
// Created by Antoine Meyer on 18/01/2022.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "ensemble.h"

#define TAILLE_INIT 10
#define COEF_TAILLE 2
#define SEUIL_REMPLISSAGE 4

/* Implémentation d'un ensemble sous forme de tableau dynamique */
struct Ensemble {
    long int *elems;
    int taille;
    int taille_max;
};

Ensemble *cree_ensemble() {
    Ensemble *res = malloc(sizeof(Ensemble));
    if (res == NULL)
        return NULL;
    res->elems = malloc(TAILLE_INIT * sizeof(long int));
    if (res->elems == NULL) {
        free(res);
        return NULL;
    }
    res->taille_max = TAILLE_INIT;
    res->taille = 0;
    return res;
}

void detruit_ensemble(Ensemble *ensemble) {
    free(ensemble->elems);
    free(ensemble);
}

int taille(const Ensemble *ensemble) {
    return ensemble->taille;
}

int localise(const Ensemble *ensemble, long int element) {
    for (int i = 0; i < ensemble->taille; i++)
        if (ensemble->elems[i] == element)
            return i;
    return -1;
}

bool appartient(const Ensemble *ensemble, long int element) {
    return localise(ensemble, element) >= 0;
}

bool redimensionne(Ensemble *ensemble, int taille) {
    long int *tmp = realloc(ensemble->elems, taille * sizeof(long int));
    if (tmp == NULL)
        return false;
    ensemble->elems = tmp;
    ensemble->taille_max = taille;
    return true;
}

/* le nouvel élément est ajouté à la fin du tableau */
int ajoute(Ensemble *ensemble, long int element) {
    if (appartient(ensemble, element))
        return 0; /* élément déjà présent, pas d'ajout */
    if (ensemble->taille == ensemble->taille_max) {
        // si l'ensemble affiche complet, on multiplie par COEF_TAILLE sa
        // capacité
        if (!redimensionne(ensemble, ensemble->taille * COEF_TAILLE))
            return -1; /* erreur d'allocation */
    }
    ensemble->elems[ensemble->taille] = element;
    ensemble->taille++;
    return 1;
}

/***************************
 * 7. Pour aller plus loin *
 ***************************/

int supprime(Ensemble *ensemble, long int element) {
    int i = localise(ensemble, element);
    if (i < 0)
        return 0; /* élément non présent, pas de suppression */
    if (ensemble->taille <= ensemble->taille_max / SEUIL_REMPLISSAGE) {
        // si l'ensemble est peu rempli, on réduit sa taille par par COEF_TAILLE
        // sa capacité
        if (!redimensionne(ensemble, ensemble->taille_max / COEF_TAILLE))
            return -1; /* erreur d'allocation */
    }
    ensemble->elems[i] = ensemble->elems[ensemble->taille - 1];
    ensemble->taille--;
    return 1;
}