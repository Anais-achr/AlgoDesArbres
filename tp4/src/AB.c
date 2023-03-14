#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/AB.h"

Arbre alloue_noeud(int val){
    Noeud* nouveau = (Noeud*) malloc(sizeof(Noeud));

    if(!nouveau)
        return NULL;
    nouveau->val = val;
    nouveau->fg = NULL;
    nouveau->fd = NULL;

    return nouveau; 
}


void affiche_arbre(Arbre a){
    if(!a) return;
    printf("%d\n", a->val);

    affiche_arbre(a->fg);
    affiche_arbre(a->fd);
}


int hauteur(Arbre a){
    int hg, hd;

    if (!a)
        return -1;
    
    hg = hauteur(a->fg);
    hd = hauteur(a->fd);

    return 1 + MAX(hg, hd);
}

int nb_noeud(Arbre a){
    if(!a)
        return 0;
    return 1 + nb_noeud(a->fg)+ nb_noeud(a->fd);
}


int nb_noeud_interne(Arbre a){
    if(!a) 
        return 0;
    if(((!a->fg) && (!a->fd)))
        return 0;
    return 1 + nb_noeud_interne(a->fg) + nb_noeud_interne(a->fd);
}


int nb_feuille(Arbre a){
    if(!a)
		return 0;
	if(!a->fg && !a->fg)
			return 1;
	return nb_feuille(a->fg)+nb_feuille(a->fd);
}


int nb_noeud_deux_fils(Arbre a){
    if(!a) 
        return 0;
    if(a->fg && a->fd)
        return 1 + nb_noeud_deux_fils(a->fg) + nb_noeud_deux_fils(a->fd);;
    return nb_noeud_deux_fils(a->fg) + nb_noeud_deux_fils(a->fd);

}


int est_strictement_binaire(Arbre a){
    if((a->fg == NULL && a->fd != NULL) || (a->fg != NULL && a->fd == NULL))
        return 0;
    return 1;
}


Arbre construit_arbre(FILE *fichier) {
    int val;
    Arbre a;

    fscanf(fichier, "%d", &val);

    if(val == 0){
        return NULL;
    }
    
    if(!(a = alloue_noeud(val)))
        return NULL;
    
    a->fg = construit_arbre(fichier);
    a->fd = construit_arbre(fichier);

    return a;
}

