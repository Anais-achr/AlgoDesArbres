#ifndef __ABR_MOT_H__
#define __ABR_MOT_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct noeud{
    char * mot;
    struct noeud *fg, *fd;
} Noeud, *Arbre;


/**
 * @brief allocation d’un nœud en recopiant strictement la chaîne de caractères 'mot' passée en argument
 * 
 * @param mot 
 * @return Noeud* 
 */
Noeud * alloue_noeud(char * mot);


/**
 * @brief affichage des mots contenus dans l’arbre A dans l’ordre d’un parcours en profondeur infixe
 * 
 * @param A 
 */
void parcours_infixe(Arbre A); 


/**
 * @brief ajoute un mot dans l'arbre A passé en argument
 * 
 * @param A 
 * @param mot 
 * @return Noeud* 
 */
Noeud * ajout(Arbre *A, char * mot);


/**
 * @brief extrait le noeud ayant le mot le plus grand dans l'arbre A.
 * 
 * @param A 
 * @return Noeud* 
 */
Noeud * extrait_max(Arbre *A);


/**
 * @brief Supprime un mot dans l'arbre A
 * 
 * @param A 
 * @param mot 
 * @return Noeud* 
 */
Noeud * suppression(Arbre * A, char * mot);


/**
 * @brief libération de tous les noeuds contenus dans l'arbre A
 * 
 * @param A 
 */
void libere(Arbre * A);

/**
 * @brief dessine un arbre A avec DOT
 * 
 * @param nom 
 * @param A 
 */
void dessine(char * nom, Arbre A);


/**
 * @brief créer un arbre à l'aide du fichier texte passé en argument
 * 
 * @param nom 
 * @param A 
 * @return int 
 */
int cree_arbre(char * nom, Arbre * A);


/**
 * @brief cherche si le mot passé en argument est préent dans l'arbre A
 * 
 * @param A 
 * @param mot 
 * @return Noeud* 
 */
Noeud* recherche(Arbre A, char* mot);
#endif