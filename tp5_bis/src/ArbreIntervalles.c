#include <stdio.h>
#include <stdlib.h>

#include "../include/ArbreIntervalles.h"

NoeudI* alloue_noeudI(Intervalle I){
    NoeudI* noeud = (NoeudI*) malloc(sizeof(NoeudI));

    if(!noeud)
        return NULL;
    noeud->i.max = I.max;
    noeud->i.min = I.min;

    noeud->fd = NULL;
    noeud->fg = NULL;

    return noeud;
}

int compareIntervalle(Intervalle I, Intervalle J){
    if(I.min != J.min)
        return I.min - J.min;
    else{
        if(I.max < J.max)
            return -1;
        if(I.max > J.max)
            return 1;
        else
            return 0;
    }
}


NoeudI* ajoute(Intervalle I, ArbreI *a){
    if(!*a){        
        (*a) = alloue_noeudI(I);
        if(!((*a)->min) && !((*a)->max)){
            (*a)->min = I.min;
            (*a)->max = I.max;
        }
            
    }
    else{
        int cmp = compareIntervalle(I, (*a)->i);

        if(cmp < 0)
            ajoute(I, &(*a)->fg);
        if(cmp > 0)
            ajoute(I, &(*a)->fd);
        if((*a)->min > I.min)
            (*a)->min = I.min;
        if((*a)->max < I.max)
            (*a)->max = I.max;
    }
    return (*a);
}

int intersecte(Intervalle I, Intervalle J){
    if((J.max >= I.min && J.max <= I.max) || (I.max >= J.min && I.max <= J.max))
        return 1;
    if((J.min >= I.min && J.min <= I.max) || (I.min >= J.min && I.min <= J.max))
        return 1;
    if((J.min >= I.min && J.max <= I.max) || (I.min >= J.min && I.max <= J.max))
        return 1;
    return 0;
    
}

int intervalleInferieur(Intervalle I, Intervalle J){
    /* return 1 si I est inférieur à J, sinon 0 */
    return (I.max < J.min);
}

ArbreI rencontreNaive(Intervalle I, ArbreI a){
    if(!a)
        return NULL;
    if(intersecte(a->i, I))
        return a;
    
    return rencontreNaive(I, a->fg);
    return rencontreNaive(I, a->fd);
}

ArbreI rencontre(Intervalle I, ArbreI a){
    if(!a)
        return NULL;
    if(intersecte(a->i, I))
        return a;
    if(intervalleInferieur(I, a->i))
        return rencontre(I, a->fg);
    if(!a->fd || a->fg->max < I.min)
        return rencontre(I, a->fd);
    else
        rencontre(I, a->fg);
    return NULL;
}

ArbreI extraitMin(ArbreI *a){
    if(!*a)
        return NULL;
    ArbreI b = *a;
    if(b->fg == NULL){
        *a = b->fd;
        b->fd = NULL;
        return b;
    }

    return extraitMin(&(b->fg));
}


NoeudI *extrait(Intervalle I, ArbreI *a){
    NoeudI *tmp, *min;
    
    if(*a == NULL)
        return *a;
    if(I.max < (*a)->min)
        (*a)->fg = extrait(I, &(*a)->fg);
    if((*a)->max < I.min)
        (*a)->fd = extrait(I, &(*a)->fd);


    
    tmp = (*a);
    printf("[%d, %d]\n", tmp->i.min, tmp->i.max);

    /* if((*A)->fg == NULL && (*A)->fd == NULL)
        *A = NULL;
    else if((*A)->fg == NULL)
        (*A) = (*A)->fd;
    else if((*A)->fd == NULL)
        (*A) = (*A)->fg;
    else{
        max = extrait_max(&(*A)->fg);
        (*A)->mot = max->mot;
    } */

    return tmp;
}

void libere(ArbreI *a){
    if(!(*a))
        return;
    libere(&(*a)->fg);
    libere(&(*a)->fd);

    free((*a));
    (*a) = NULL;
} 