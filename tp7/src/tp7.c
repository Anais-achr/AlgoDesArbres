#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/UnionFind.h"


int main(int argc, char** argv){
    int N = 50000, M = 100;
    int seed = 12345;
    int x, y; 

    struct timespec startNaif, endNaif; 
    struct timespec startCompresse, endCompresse; 
    double sec_d_naif, sec_f_naif, nsec_d_naif, nsec_f_naif, sec_total_naif;
    double sec_d_compresse, sec_f_compresse, nsec_d_compresse, nsec_f_compresse, sec_total_compresse;

    UnionFind *arbre_naif, *arbre_compresse;

    // Initialiser la graine pour la génération aléatoire
    srandom(seed);

    // Teste naïf
    arbre_naif = initialisation(N);
    clock_gettime(CLOCK_REALTIME, &startNaif);
    for (int i = 0; i < M; i++) {
        x = random() % N;
        y = random() % N;
        fusion_naive(arbre_naif, x, y);
    }
    clock_gettime(CLOCK_REALTIME, &endNaif);
    sec_d_naif = startNaif.tv_sec;              //temps debut seconde
    nsec_d_naif = startNaif.tv_nsec*0.00000001; //temps debut nanoseconde

    sec_f_naif = endNaif.tv_sec;                //temps fin seconde
    nsec_f_naif = endNaif.tv_nsec*0.00000001;   //temps fin nanoseconde

    sec_total_naif = (sec_f_naif+nsec_f_naif) - (sec_d_naif+nsec_d_naif);

    printf("\n\n");


    srandom(seed); //on reinitialise la graine pour la génération aléatoire


    //Teste compresse
    arbre_compresse = initialisation(N);
    clock_gettime(CLOCK_REALTIME, &startCompresse);
    for (int i = 0; i < M; i++) {
        x = random() % N;
        y = random() % N;
        fusion_rang(arbre_compresse, x, y);

    }
    clock_gettime(CLOCK_REALTIME, &endCompresse);
    sec_d_compresse = startCompresse.tv_sec;             //temps debut seconde
    nsec_d_compresse = startCompresse.tv_nsec*0.00000001;//temps debut nanoseconde

    sec_f_compresse = endCompresse.tv_sec;              //temps fin seconde
    nsec_f_compresse = endCompresse.tv_nsec*0.00000001; //temps fin nanoseconde

    sec_total_compresse = (sec_f_compresse+nsec_f_compresse) - (sec_d_compresse+nsec_d_compresse);


    printf("----- Naif -----\n");
    printf("    Nombre d'appels : %d\n", arbre_naif->nb_appels);
    printf("    Temps d'exécution de l'algorithme naïf :  %.9f secondes\n", sec_total_naif);
    printf("\n");
    printf("----- Compresse -----\n");
    printf("    Nombre d'appels : %d\n", arbre_compresse->nb_appels);
    printf("    Temps d'exécution de l'algorithme amélioré :  %.9f secondes\n", sec_total_compresse);


    free(arbre_naif->pere);
    free(arbre_naif->rang);
    free(arbre_naif);
    free(arbre_compresse->pere);
    free(arbre_compresse->rang);
    free(arbre_compresse);

    return 0;
}
