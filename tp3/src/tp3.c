#include <stdio.h>

#include "../include/ABR.h"

int main(int argc, char** argv){
    Arbre a;
    a = construit_ABR();

    /* Arbre pas abr */
    /* a = alloue_noeud(24);
    a->fg = alloue_noeud(16);
    a->fg->fg = alloue_noeud(11);
    a->fg->fg->fg = alloue_noeud(10);
    a->fg->fg->fd = alloue_noeud(14);
    a->fd = alloue_noeud(29);
    a->fd->fg = alloue_noeud(25);
    a->fd->fd = alloue_noeud(31);
    a->fd->fg->fg = alloue_noeud(23);
    a->fd->fg->fd = alloue_noeud(26); */


    /* Arbre abr */
    /* a = alloue_noeud(20);
    a->fg = alloue_noeud(13);
    a->fg->fg = alloue_noeud(8);
    a->fg->fg->fg = alloue_noeud(7);
    a->fg->fg->fd = alloue_noeud(11);

    a->fd = alloue_noeud(23);
    a->fd->fg = alloue_noeud(21);
    a->fd->fd = alloue_noeud(27); */

    affiche_ABR(a);
    printf("\n");

    /* Ex 3 */
    printf("\n");
    printf("hauteur = %d\n", hauteur(a));
    printf("min = %d\n", min_abr(a)->val);
    printf("max = %d\n", max_abr(a)->val);
    printf("nombre de noeuds = %d\n", nb_noeud(a));
    printf("nombre de feuilles = %d\n", nb_feuille(a));

    if(est_abr(a))
        printf("ABR");
    else
        printf("Pas ABR");

    libere(&a);
    return 0;
}