#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/ABR.h"
#include "../include/Utils.h"


int filtre(Arbre *A, Arbre Afiltre, Arbre * utilises){
    if(!(*A))
        return 0;

    Noeud* tmp = recherche(Afiltre, (*A)->mot);

    if(tmp){
        ajout(utilises, tmp->mot);
        suppression(A, tmp->mot);
    }

    return filtre(&(*A)->fg, Afiltre, utilises) || filtre(&(*A)->fd, Afiltre, utilises);
}



int main(int argc, char** argv){
    Arbre A = NULL, Afiltre = NULL, utilises = NULL;
    char *nom1 = NULL, *nom2 = NULL;
    int pdf = 0;
    char* format;

    
    /* On traite les arguments */
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-v") == 0)
            pdf = 1;
        else{
            format = strstr(argv[i], ".txt");
            if(strcmp(format, ".txt") == 0){
                if(nom1 == NULL)
                    nom1 = nom_fichier("", argv[i], "");
                else
                    nom2 = nom_fichier("", argv[i], "");
            }
        }
    }

    if(nom1 == NULL || nom2 == NULL){
        printf("Veuillez passer exactement deux fichiers en arguments\n");
        exit(0);
    }


    /* Les arguments sont correctes donc on continu */
    cree_arbre(nom1, &A);
    cree_arbre(nom2, &Afiltre);  

    if(pdf){
        dessine("texte", A);
        dessine("filtre", Afiltre);
    }

    filtre(&A, Afiltre, &utilises);
    printf("Mots présents uniquement dans le texte de référence : \n");
    printf("-----------------------------------------------------\n");
    parcours_infixe(A);

    printf("\n\n");

    printf("Mots présents dans les deux textes :\n");
    printf("------------------------------------\n");
    parcours_infixe(utilises);

    if(pdf){
        dessine("filtrage", A);
        dessine("en_commun", utilises);
    }

    libere(&A);
    libere(&Afiltre);
    libere(&utilises); 

    free(nom1);
    free(nom2);
    
    return 0;
}