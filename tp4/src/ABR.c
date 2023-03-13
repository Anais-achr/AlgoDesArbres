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


int min_abr(Arbre a){
    if(!a) return 0;

    if(a->fg == NULL)
        return a->val;
    return min_abr(a->fg);
} 


int max_abr(Arbre a){
    if(!a) return 0;
    
    if(a->fd == NULL)
        return a->val;
    return max_abr(a->fd);
}


int est_abr_aux(Noeud* noeud, int min, int max) {
    if (noeud == NULL) {
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

    do{
        printf("inserer une valeur. stop : 'stop'\n");
        scanf("%s", n); 
        ajoute_abr(&a, atoi(n));
    }while(strcmp(n, "stop"));

    return a;
}


Noeud* extrait_min(Arbre *a){
    Noeud* tmp;
    if(!*a){
        return 0;
    }
    if(!((*a)->fg)){
        tmp=(*a);
        (*a)=(*a)->fd;
        return tmp;
    }
    return extrait_min(&((*a)->fg));
}



Noeud* extrait_max(Arbre *a){
    Noeud* tmp;
    if(!*a){
        return 0;
    }
    if(!((*a)->fd)){
        tmp=(*a);
        (*a)=(*a)->fg;
        return tmp;
    }
    return extrait_max(&((*a)->fd));
}

void libere(Arbre *a){
    if(!*a)
        return;
    libere(&(*a)->fg);
    libere(&(*a)->fd);

    free((*a));
    (*a) = NULL;
}