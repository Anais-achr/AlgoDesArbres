#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/ABR.h"
#include "../include/Visualisation.h"
#include "../include/Utils.h"

Noeud * alloue_noeud(char * mot){
    Noeud *tmp = (Noeud*) malloc(sizeof(Noeud));
    
    if(!tmp)
        return NULL;

    tmp->mot = (char*) malloc(sizeof(char)*strlen(mot));
    if(!tmp->mot){
        return NULL;
    }
    tmp->mot = strcpy(tmp->mot, mot);
    tmp->fd = NULL;
    tmp->fg = NULL;

    return tmp;
}


void parcours_infixe(Arbre A){
    if(!A)
        return;
    parcours_infixe(A->fg);
    printf("%s\n", A->mot);
    parcours_infixe(A->fd);
}


Noeud * ajout(Arbre *A, char * mot){
    if (!*A)
        return (*A = alloue_noeud(mot));
    
    else{
        if (mon_strcmp(mot, (*A)->mot) < 0)
            ajout(&(*A)->fg, mot);
        else if (mon_strcmp(mot, (*A)->mot) >= 1)
            ajout(&(*A)->fd, mot);
    }
    return NULL;
}


Noeud * extrait_max(Arbre *A){
    Noeud* tmp;
    if (!*A)
        return NULL;
    if (!(*A)->fd){
        tmp = (*A);
        (*A) = (*A)->fg;
        return tmp;
    }
    return extrait_max(&((*A)->fd));
}


Noeud * suppression(Arbre * A, char * mot){
    Noeud *tmp, *max;


    if(*A == NULL)
        return *A;
    if(mon_strcmp((*A)->mot, mot) >= 1)
        return suppression(&(*A)->fg, mot);
    if(mon_strcmp((*A)->mot, mot) < 0)
        return suppression(&(*A)->fd, mot);
    
    tmp = (*A);
    free((*A)->mot);


    if((*A)->fg == NULL && (*A)->fd == NULL){
        *A = NULL;
    }
    else if((*A)->fg == NULL && (*A)->fd != NULL)
        (*A) = (*A)->fd;
    else if((*A)->fd == NULL && (*A)->fg!= NULL)
        (*A) = (*A)->fg;
    else{
        max = extrait_max(&(*A)->fg);
        (*A)->mot = max->mot;
        free(max);
        max = NULL;
    } 
    return tmp;
}



void libere(Arbre * A){
    if(!(*A))
        return;
    libere(&(*A)->fg);
    libere(&(*A)->fd);

    free((*A)->mot);
    free((*A));
    (*A) = NULL;
} 


void dessine(char * nom, Arbre A){

    char* nom_fichier_dot = nom_fichier("arbre_dot/dot/", nom, ".dot");
    char* nom_fichier_pdf = nom_fichier("arbre_dot/pdf/", nom, ".pdf");

    FILE *out = fopen(nom_fichier_dot, "w");
    
    creerPDF(nom_fichier_dot, nom_fichier_pdf, A); 

    fclose(out);

    free(nom_fichier_dot);
    free(nom_fichier_pdf);
}


int cree_arbre(char * nom, Arbre * A){
    FILE* f = fopen(nom, "r");

    /* On vérifie que le fichier existe avant de l'utiliser*/
    if(!f){
        printf("Erreur: le fichier %s n'exsite pas\n", nom);
        exit(0);
    }
    char buffer[512];
    char *separateurs = " \n,;:.?!\"()-’";
    
    while(!feof(f)){ // tant qu'on à pas fini de lire le fichier
        fgets(buffer, 512, f); // on récupère les mots par tranche de 512 caractères
        char *mot = strtok(buffer, separateurs);
        while (mot != NULL ){
            ajout(A, mot);
            mot = strtok(NULL, separateurs);
            /* 
                l'argument NULL passé à strtok permet de spécifier 
                qu'on continu la séparation sur la même chaine de caractère
             */
        }
    }

    fclose(f);
    return 1;
}


Noeud* recherche(Arbre A, char* mot){
    if(!A) 
        return NULL;
    if(mon_strcmp(A->mot, mot) == 0)
        return A;
    if(mon_strcmp(A->mot, mot) >= 1)
        return recherche(A->fg, mot);
    return recherche(A->fd, mot);
}