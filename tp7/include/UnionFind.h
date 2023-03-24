#ifndef __UNION_FIND_H__
#define __UNION_FIND_H__


typedef struct{
    int taille;
    int *pere;
    int *rang;
    int nb_appels;
}UnionFind;


void affiche(UnionFind *partition);
UnionFind* initialisation(int N);
int trouve_naif(UnionFind* partition, int x);
void fusion_naive(UnionFind *partition, int x, int y);
int trouve_compresse(UnionFind *partition, int x);
void fusion_rang(UnionFind *partition, int x, int y);

#endif