#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * @brief compare deux mots en ordre alphabétique et léxicographique
 * 
 * @param mot1 
 * @param mot2 
 * @return renvoie 1 si mot1 > mot2, renvoie -1 si mot1 < mot2, sinon 0 (mots égaux)
 */
int mon_strcmp(const char *mot1, const char *mot2);


/**
 * @brief Formate un nom de fichier avec son chemin et son nom et son format
 * 
 * @param chemin 
 * @param nom 
 * @param format 
 * @return char* 
 */
char* nom_fichier(char* chemin, char* nom, char* format);

#endif