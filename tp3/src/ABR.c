#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "../include/ABR.h"
#include "../include/AB.h"



void affiche_ABR(Arbre a){
    if(!a) return;
    affiche_ABR(a->fg);
    printf("%d ", a->val);
    affiche_ABR(a->fd);
}


Noeud* recherche(Arbre a, int n){
    if(!a) return NULL;
    if(a->val == n)
        return a;
    if(a->val > n)
        return recherche(a->fg, n);
    return recherche(a->fd, n);
}


void ajoute_abr(Arbre *a, int n){
    if(!*a){
        *a = alloue_noeud(n);
    }else{
        if(n < (*a)->val)
            ajoute_abr(&(*a)->fg, n);
        else if(n > (*a)->val)
            ajoute_abr(&(*a)->fd, n);
        else
            return;
    }
}



Noeud* min_abr(Arbre a){
    if(a && a->fg) 
        return min_abr(a->fg);
    else
        return a;
} 


Noeud* max_abr(Arbre a){
    if(a && a->fd) 
        return max_abr(a->fd);
    else
        return a;
}


int est_abr_aux(Noeud* noeud, int min, int max) {
    if (!noeud){
        return 1;
    }
    if (noeud->val < min || noeud->val > max) {
        return 0;
    }
    return est_abr_aux(noeud->fg, min, noeud->val) &&
           est_abr_aux(noeud->fd, noeud->val, max);
}

int est_abr(Arbre a) {
    return est_abr_aux(a, INT_MIN, INT_MAX);
}



Arbre construit_ABR(){
    Arbre a = NULL;
    char n[20];
    int continuer = 1;

    while(continuer){
        printf("inserer une valeur. stop : 'stop'\n");
        scanf("%s", n); 
        if(strcmp(n, "stop") != 0)
            ajoute_abr(&a, atoi(n));
        else
            continuer = 0;
    }
    
    return a;
}



