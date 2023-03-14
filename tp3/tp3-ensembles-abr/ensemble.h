#ifndef ENSEMBLE_H
#define ENSEMBLE_H

#include <stdbool.h>

/* Type alias */
typedef struct Ensemble Ensemble;
/* La définition du type dépend de l'implémentation et se situe dans le .c */

/* Renvoie l'adresse d'un nouvel ensemble */
Ensemble *cree_ensemble();

/* Libère l'espace alloué pour `ensemble` */
void detruit_ensemble(Ensemble *ensemble);

/* Renvoie la taille de `ensemble` */
int taille(const Ensemble *ensemble);



/* Renvoie 1 si `element` est dans `ensemble`, 0 sinon */
bool appartient(const Ensemble *ensemble, long int element);

/*
 * Ajoute `element` à `ensemble` et renvoie
 *  -1 en cas d'échec
 *   0 si l'élément est déjà dans l'ensemble
 *   1 sinon
 *
 */
int ajoute(Ensemble *ensemble, long int element);

/***************************
 * 7. Pour aller plus loin *
 ***************************/

/*
 * Supprime `element` de `ensemble` et renvoie
 *  -1 en cas d'échec
 *   0 si l'élément n'est pas dans l'ensemble
 *   1 sinon
 *
 */
int supprime(Ensemble *ensemble, long int element);

#endif
