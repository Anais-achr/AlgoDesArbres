#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/AB.h"

int main(int argc, char** argv){
    
    /*Arbre a = alloue_noeud(1);
    a->fg = alloue_noeud(2);
    a->fd = alloue_noeud(5);

    a->fg->fg = alloue_noeud(3);
    a->fg->fd = alloue_noeud(4);
    
    a->fd->fd = alloue_noeud(6);
    a->fd->fg = alloue_noeud(7); */


    FILE* f = fopen(argv[1], "r");

    if(!f){
        printf("Aucun fichier passé en argument");
        exit(0);
    }
    
    Arbre a;
    a = construit_arbre(f); 


    printf("hauteur = %d\n", hauteur(a));
    printf("nb noeuds = %d\n", nb_noeud(a));
    printf("nb noeuds internes = %d\n", nb_noeud_interne(a));
    printf("nb feuilles = %d\n", nb_feuille(a));
    printf("nb deux fils = %d\n", nb_noeud_deux_fils(a));
    printf("strictement binaire ? %d\n", est_strictement_binaire(a));

    fclose(f);
    return 0;
}