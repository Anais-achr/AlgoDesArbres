//
// Created by Antoine Meyer on 18/01/2022.
//

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "ensemble.h"

typedef struct cellule {
    long int valeur;
    struct cellule *suivant;
} Cellule;

struct Ensemble {
    Cellule *premier;
    int taille;
};

Cellule* cree_cellule(long int elem) {
    Cellule *res = malloc(sizeof(Cellule));
    res->valeur = elem;
    res->suivant = NULL;
    return res;
}

void detruit_cellule(Cellule *cellule) {
    free(cellule);
}

Ensemble* cree_ensemble() {
    Ensemble *tmp = malloc(sizeof(struct Ensemble));
    tmp->premier = NULL;
    tmp->taille = 0;
    return tmp;
}

void detruit_ensemble(Ensemble *ens) {
    Cellule *courant, *suivant;
    courant = ens->premier;
    while (courant != NULL) {
        suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
    free(ens);
}

Cellule* trouve_cellule(Cellule *cellule, long int elem) {
    for(; cellule; cellule = cellule->suivant){
        if(cellule->valeur == elem)  
            return cellule;
    }
    return NULL;
} //O(n)

bool appartient(const Ensemble *ens, long int elem) {
    return trouve_cellule(ens->premier, elem) != NULL;
    //O(n)
}

int ajoute(Ensemble *ens, long int elem) {
    if(appartient(ens, elem))
        return 0;
    
    Cellule* new_cel = cree_cellule(elem);
    if(!new_cel)
        return -1;

    if(!ens->premier)
        ens->premier = new_cel;

    else{
        new_cel->suivant = ens->premier;
        ens->premier = new_cel;
    }
    ens->taille+=1;
    return 1;
    //O(n)
}


int taille(const Ensemble *ens) {
    return ens->taille;

    //O(1)
}
