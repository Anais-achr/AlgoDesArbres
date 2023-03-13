#ifndef VISUALISATION_H
#define VISUALISATION_H

#include <stdio.h>
#include <string.h>

#include "./AB.h"

void ecrireDebut(FILE *f);
void ecrireArbre(FILE *f, Arbre a);
void ecrireFin(FILE *f);
void dessine(FILE *f, Arbre a);
void creerPDF(char *dot , char *pdf , Arbre a);

#endif