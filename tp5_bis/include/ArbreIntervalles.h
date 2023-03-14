#ifndef __ARBRE_INTERVALLES_H__
#define __ARBRE_INTERVALLES_H__

typedef struct{
    int min;
    int max;
}Intervalle;


typedef struct noeudI{
    Intervalle i;
    int min;
    int max;
    struct noeudI *fg;
    struct noeudI *fd;
}NoeudI , *ArbreI;

NoeudI* alloue_noeudI(Intervalle I);
int compareIntervalle(Intervalle I, Intervalle J);
NoeudI* ajoute(Intervalle I, ArbreI *a);
int intersecte(Intervalle I, Intervalle J);
ArbreI rencontreNaive(Intervalle I, ArbreI a);
int intervalleInferieur(Intervalle I, Intervalle J);
ArbreI rencontre(Intervalle I, ArbreI a);
NoeudI* extraitMin(ArbreI *a);
ArbreI extrait(Intervalle I, ArbreI *a);

void libere(ArbreI *a);
#endif