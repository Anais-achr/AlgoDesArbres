#include <stdio.h>

#include "../include/ArbreIntervalles.h"
#include "../include/Visualisation.h"

int main(int argc, char** argv){
    FILE *f = fopen("arbreI.dot" ,"w");
    FILE *f2 = fopen("arbreI2.dot" ,"w");

    ArbreI a = NULL;

    Intervalle i1;
    i1.max = 22;
    i1.min = 19;

    Intervalle i2;
    i2.max = 31;
    i2.min = 27;

    Intervalle i3;
    i3.max = 12;
    i3.min = 10;

    Intervalle i4;
    i4.max = 35;
    i4.min = 26;
    
    Intervalle i5;
    i5.max = 32;
    i5.min = 28;

    ajoute(i1, &a);
    ajoute(i2, &a);
    ajoute(i3, &a);
    ajoute(i4, &a);
    ajoute(i5, &a);
    
        /* printf("[%d, %d] intersecte [%d, %d]\n", i4.min, i4.max, a->min, a->max);
    printf("min = %d, max = %d\n", a->min, a->max); */

    creerPDF("arbreI.dot", "arbreI.pdf", a);
    NoeudI* res = extrait(i4, &a);
    if(res)
        printf("[%d, %d]\n", res->i.min, res->i.max);
    creerPDF("arbreI2.pdf", "arbreI2.pdf", a);

    fclose(f);
    fclose(f2);
    
    libere(&a);
    return 0;
}