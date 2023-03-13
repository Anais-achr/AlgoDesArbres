#ifndef __VISUALISATION_H__
#define __VISUALISATION_H__

#include <stdio.h>
#include <string.h>

#include "./ArbreIntervalles.h"

void ecrireDebut(FILE *f);
void ecrireArbre(FILE *f, ArbreI a);
void ecrireFin(FILE *f);
void dessine(FILE *f, ArbreI a);
void creerPDF(char *dot , char *pdf , ArbreI a);

#endif