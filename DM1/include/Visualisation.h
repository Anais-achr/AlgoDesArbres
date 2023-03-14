#ifndef __VISUALISATION_H__
#define __VISUALISATION_H__

#include <stdio.h>
#include <string.h>

#include "./ABR.h"


/**
 * @brief Écrit le début d'un fichier dot
 * 
 * @param f 
 */
void ecrireDebut(FILE *f);

/**
 * @brief Écrit les lignes nécessaire en langage dot d'un arbre
 * 
 * @param f 
 * @param a 
 */
void ecrireArbre(FILE *f, Arbre a);

/**
 * @brief Écrit la fin d'un fichier dot
 * 
 * @param f 
 */
void ecrireFin(FILE *f);

/**
 * @brief Écrit entierement le fichier dot d'un arbre
 * 
 * @param f 
 * @param a 
 */
void dessine_dot(FILE *f, Arbre a);

/**
 * @brief Créer le fichier pdf d'un fichier dot
 * 
 * @param dot 
 * @param pdf 
 * @param a 
 */
void creerPDF(char *dot , char *pdf , Arbre a);

#endif