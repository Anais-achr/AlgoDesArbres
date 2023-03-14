#include <stdio.h>
#include <stdlib.h>

#include "../include/Tas.h"

int est_tas(int tab[], int taille){
    for (int i = 0; i < taille; i++){
        if (tab[i] < tab[(i - 1) / 2] || tab[i] == 0 || tab[(i - 1) / 2] == 0)
            return 0;
    }
    return 1;
}

void affiche_tas(int tab[], int taille){
    for (int i = 0; i < taille; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
}

int enum_permutation(int tab[], int premier, int n){
    int res = 0;

    if (premier > n)
        return 1;

    for (int i = 0; i < n; i++){
        if (tab[i] == 0){
            tab[i] = premier;
            affiche_tas(tab, n);
            res += enum_permutation(tab, premier + 1, n);
            tab[i] = 0;
        }
    }

    return res;
}

int enum_tas_naif(int tab[], int premier, int n){
    int res = 0;

    if (premier > n){
        if (est_tas(tab, n)){
            affiche_tas(tab, n);
            return 1;
        }
    }

    for (int i = 0; i < n; i++){
        if (tab[i] == 0){
            tab[i] = premier;
            res += enum_tas_naif(tab, premier + 1, n);
            tab[i] = 0;
        }
    }

    return res;
}

int est_tas_partiel(int tab[], int n){
    for (int i = 1; i < n; i++){
        if(tab[i] == 0)
            continue;
        if((tab[i] < tab[(i - 1) / 2]))
            return 0;
    }
    return 1;
}

int enum_tas_verif(int tab[], int premier, int n){
    int res = 0;

    if(est_tas(tab, n)){
        affiche_tas(tab, n);
        return 1;
    }


    for (int i = 0; i < n; i++){
        if (tab[i] == 0){
            tab[i] = premier;
            if(est_tas_partiel(tab, n)){
                res += enum_tas_verif(tab, premier+1, n);
            }
            tab[i] = 0;
        }
    }

    return res;
}

int enum_tas(int tab[], int premier, int n){
     int res = 0;

    if(est_tas(tab, n)){
        affiche_tas(tab, n);
        return 1;
    }


    for (int i = 0; i < n; i++){
        if (tab[i] == 0 && (i == 0 || tab[(i-1)/2] != 0)){
            tab[i] = premier;
            if(est_tas_partiel(tab, n)){
                res += enum_tas(tab, premier+1, n);
            }
            tab[i] = 0;
        }
    }

    return res;
}
