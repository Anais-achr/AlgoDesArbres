#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "ensemble.h"

typedef struct noeud {
    long int valeur;
    struct noeud *fg;
    struct noeud *fd;
} Noeud, *Arbre;

struct Ensemble {
    Noeud *racine;
    int taille;
};

static Noeud *alloue_noeud(long int elem) {
    Noeud *res = malloc(sizeof(Noeud));
    res->valeur = elem;
    res->fg = NULL;
    res->fd = NULL;
    return res;
}

static void detruit_noeud(Noeud *noeud) {
    free(noeud);
}

static void detruit_arbre(Noeud *noeud) {
    if (noeud == NULL)
        return;
    else {
        detruit_arbre(noeud->fg);
        detruit_arbre(noeud->fd);
        detruit_noeud(noeud);
    }
}

Ensemble *cree_ensemble() {
    Ensemble *tmp = (Ensemble *)malloc(sizeof(struct Ensemble));
    tmp->racine = NULL;
    tmp->taille = 0;
    return tmp;
}

void detruit_ensemble(Ensemble *ens) {
    detruit_arbre(ens->racine);
    free(ens);
}

int taille(const Ensemble *ens) {
    return ens->taille;
} /* O(1) */


Noeud* recherche(Arbre a, long int n){
    if(!a) return NULL;
    if(a->valeur == n)
        return a;
    if(a->valeur > n)
        return recherche(a->fg, n);
    return recherche(a->fd, n);
} 


bool appartient(const Ensemble *ens, long int elem){
    if(recherche(ens->racine, elem) != NULL)
        return true;
    return false;
}/* O(hauteur) */

int ajoute_aux(Arbre *a, long int n){
    if(!*a){
        if(!(*a = alloue_noeud(n))) 
            return -1;
    }
    else{
        if((*a)->valeur > n)
            ajoute_aux(&(*a)->fg, n);
        else if((*a)->valeur < n)
            ajoute_aux(&(*a)->fd, n);
    }
    return 1;
} /* O(hauteur) */


int ajoute(Ensemble *ens, long int elem) {

    if(appartient(ens, elem))
        return 0;

    int res = ajoute_aux(&(ens->racine), elem);
    if(res == 1){
        ens->taille++;
        return 1;
    }
    else
        return -1;
} /* O(hauteur) */ 
