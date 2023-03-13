#ifndef __ABR_H__
#define __ABR_H__

#include "../include/AB.h"

/**
 * @brief Affiche un arbre binaire de recherche en ordre infixe
 * 
 * @param a 
 */
void affiche_ABR(Arbre a);

/**
 * @brief recherche un noeud dans un arbre binaire de recherche
 * 
 * @param a 
 * @param n 
 * @return Noeud* 
 */
Noeud* recherche(Arbre a, int n);

/**
 * @brief ajoute un noeud, sans doublons, dans un arbre binaire de recherche
 * 
 * @param a 
 * @param n 
 */
void ajoute_abr(Arbre *a, int n);

/**
 * @brief Recherche la valeur minimale présente dans un arbre binaire de recherche 
 * 
 * @param a 
 * @return int 
 */
int min_abr(Arbre a);

/**
 * @brief Recherche la valeur maximale présente dans un arbre binaire de recherche 
 * 
 * @param a 
 * @return int 
 */
int max_abr(Arbre a);


/**
 * @brief Fonction auxiliaire qui determine si un arbre est un arbre binaire de recherche 
 *          en testant si la valeur d'un noeud est dans l'intevalle ]min, max[
 * 
 * @param a 
 * @return int 
 */
int est_abr_aux(Noeud* noeud, int min, int max);


/**
 * @brief Determine si un arbre est un arbre bianire de recherche
 * 
 * @param a 
 * @return int 
 */
int est_abr(Arbre a);



/**
 * @brief Construit un arbre binaire de recherche en demandant à l'utilisateur l'entrée de valeurs
 * 
 * @return Arbre 
 */
Arbre construit_ABR();



Noeud* extrait_min(Arbre *a);
Noeud* extrait_max(Arbre *a);
void libere(Arbre *a);
#endif