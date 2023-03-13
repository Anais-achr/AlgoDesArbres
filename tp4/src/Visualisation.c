#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/Visualisation.h"
#include "../include/AB.h"

void ecrireDebut(FILE *f){
    fprintf(f, "digraph arbre {\n");
    fprintf(f, "    node [shape=record, height=.1]\n");
    fprintf(f, "    edge [tailclip=false, arrowtail = dot, dir=both];\n");
}

void ecrireArbre(FILE *f, Arbre a){
    if(!a)
        return;
    fprintf(f, "    n%p [label=\"<gauche> | <valeur> %d | <droit>\"];\n", a, a->val);
    if(a->fg)
        fprintf(f, "    n%p: gauche:c -> n%p:valeur;\n", a, a->fg);
    
    if(a->fd)
        fprintf(f, "    n%p: droit:c -> n%p:valeur;\n", a, a->fd);

    ecrireArbre(f, a->fg);
    ecrireArbre(f, a->fd);   
}

void ecrireFin(FILE *f){
    fprintf(f, "\n}");
}

void dessine(FILE *f, Arbre a){
    ecrireDebut(f);
    ecrireArbre(f, a);
    ecrireFin(f);
}


void creerPDF(char *dot, char *pdf, Arbre a){
    FILE *out = fopen(dot ,"w");
    dessine(out ,a);
    fclose(out);
    int len = strlen(dot) + strlen(pdf) + 15;
    char cmd[len];
    strcpy(cmd , "dot -Tpdf ");
    strcat(cmd , dot);
    strcat(cmd , " -o ");
    strcat(cmd , pdf);
    system(cmd);
}