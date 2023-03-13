#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/AB.h"
#include "../include/Visualisation.h"
#include "../include/ABR.h"


int main(int argc, char** argv){
    FILE *f = fopen("arbre.dot" ,"w");
   
    /* FILE *fa = fopen(argv[1], "r"); */
    char n[5];
    int continuer = 1;
    Arbre a = NULL; /* = construit_arbre(fa); */
    
    creerPDF("arbre.dot", "arbre.pdf", a);
    /* system("open arbre.pdf"); */ /* sous mac*/

    while(continuer){
        printf("inserer une valeur. stop : 'stop'\n");
        scanf("%s", n);
        if(strcmp(n, "stop")){
            ajoute_abr(&a, atoi(n));
            creerPDF("arbre.dot", "arbre.pdf", a);
        }
        else
            continuer = 0;
    }
    /* fclose(fa); */
    Noeud* min = extrait_min(&a);
    creerPDF("arbre.dot", "arbre.pdf", a);


    Noeud* max = extrait_max(&a);
    creerPDF("arbre.dot", "arbre.pdf", a);

    printf("min = %d\n", min->val);
    printf("max = %d\n", max->val);


    fclose(f);

    free(min);
    free(max);

    libere(&a);

    return 0;
}