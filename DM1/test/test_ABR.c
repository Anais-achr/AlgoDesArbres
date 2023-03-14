#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/ABR.h"
#include "../include/Visualisation.h"
#include "../include/Utils.h"


//Pas correcte :
    //ne comprend pas les accents 

/* int mon_strcmp(const char *mot1, const char *mot2){
    int i = 0;
    
    while (mot1[i] != '\0' && mot2[i] != '\0'){
        if(mot1[i] != mot2[i]){
            if (mot1[i] > mot2[i])
                return 1;
            if (mot1[i] < mot2[i])
                return -1;
        }
        i++;

    }
    return 0;
}  */


int main(int argc, char **argv){
    Arbre a = NULL;

    if(argc < 2){
        printf("Aucun fichier passé en arguments.\n");
        exit(0);
    }
    
    cree_arbre(argv[1], &a);
    dessine("avantSupression", a);

    suppression(&a, "arbre");
    dessine("apresSupression", a);

    libere(&a);
    return 0;
}