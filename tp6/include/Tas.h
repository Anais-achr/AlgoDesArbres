#ifndef __TAS_H__
#define __TAS_H__

#define MAX 100

typedef struct {
    int taille;
    int arbre[MAX];
} Tas;


int est_tas(int tab[], int taille);
void affiche_tas(int tab[], int taille);
int enum_permutation(int tab[], int premier, int n);
int enum_tas_naif(int tab[], int premier, int n);
int est_tas_partiel(int tab[], int n);
int enum_tas_verif(int tab[], int premier, int n);
int enum_tas(int tab[], int premier, int n);

#endif