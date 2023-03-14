#include <stdio.h>
#include "../include/Tas.h"


int main(int argc, char** argv){

    /* int taille1 = 10;
    int tab1[] = {2, 5, 7, 18, 11, 15, 9, 21, 37, 17};

    int res = est_tas(tab1, taille1); */

    /* res ? affiche_tas(tab1, taille1): printf("pas un tas\n"); */

    
    /* int res2 = enum_permutation(tab2, 1, 4);
    printf("res2 = %d\n", res2); */

   /*  printf("\n\n");

    int res3 = enum_tas_naif(tab2, 1, 4);
    printf("res3 = %d\n", res3); */


    //int tab[4] = {1, 2, 3, 4};

    /* int res4 = enum_tas_verif(tab2, 1, 4);
    printf("res4 = %d\n", res4); */

    int n = 4;
    int tab2[4] = {0, 0, 0, 0};

    int res5 = enum_tas(tab2, 1, n);
    printf("res5 = %d\n", res5);
    return 0;
}