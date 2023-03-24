#include <stdio.h>
#include <stdlib.h>

#include "../include/UnionFind.h"
#define MAX(a, b) ((a > b) ? a : b)


void affiche(UnionFind *partition){
    int tmp = partition->nb_appels;

    for(int i=0; i<partition->taille; i++){
        if(partition->pere[i] == i){
            int rep_i = trouve_naif(partition, partition->pere[i]);
            printf("{%d", i);

            for(int j=0; j<partition->taille; j++){
                int rep_j = trouve_naif(partition, partition->pere[j]);

                if(rep_i == rep_j && rep_i != j)
                    printf(", %d", j);
            }
            printf("} ");
        }
    }
    partition->nb_appels = tmp;
}


UnionFind* initialisation(int N){
    if(N <= 0)
        return NULL;

    UnionFind* partition = (UnionFind*)malloc(sizeof(UnionFind));
    if(!partition)
        return NULL;
    
    partition->pere = (int*)malloc(sizeof(int)*N);
    partition->rang = (int*)malloc(sizeof(int)*N);

    if(!partition->pere || !partition->rang)
        return NULL;
    
    for(int i = 0; i < N; i++){
        partition->pere[i] = i;
        partition->rang[i] = 0;
    }

    partition->taille = N;
    partition->nb_appels = 0;

    return partition;
}


int trouve_naif(UnionFind* partition, int x){
    while(partition->pere[x] != x){
        x = partition->pere[x];
        partition->nb_appels++;
    }
    return x;
}


void fusion_naive(UnionFind *partition, int x, int y){
    int rep_x = trouve_naif(partition, x);
    int rep_y = trouve_naif(partition, y);

    if(rep_x != rep_y){
        partition->pere[y] = rep_x;
        partition->nb_appels++;
        partition->rang[rep_x] += partition->rang[rep_y] + 1;/* MAX(partition->rang[pere_x], partition->rang[pere_y]) */;
    }    
}  


int trouve_compresse(UnionFind *partition, int x){
    if(partition->pere[x] != x){
        partition->pere[x] = trouve_compresse(partition, partition->pere[x]);
        partition->nb_appels++;
    }
    return partition->pere[x];
}

void fusion_rang(UnionFind *partition, int x, int y) {
    int rep_x = trouve_compresse(partition, x);
    int rep_y = trouve_compresse(partition, y);

    if (rep_x == rep_y) {
        partition->pere[y] = rep_x;
        partition->rang[x] += partition->rang[y] + 1;
        partition->nb_appels++;
    }

    if(rep_x != rep_y) {
        partition->nb_appels++;
        if (partition->rang[rep_x] < partition->rang[rep_y]) {
            partition->nb_appels++;
            partition->pere[x] = rep_y;
            partition->rang[y] += partition->rang[x] + 1;
        } else {
            partition->nb_appels++;
            partition->pere[y] = rep_x;
            partition->rang[x] += partition->rang[y] + 1;
        }
    }

}