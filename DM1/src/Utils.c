#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/Utils.h"

int mon_strcmp(const char *mot1, const char *mot2){
    /* Explication :
    Tant que le caractère à la position i du mot1 et du mot2 sont les mêmes alors on avance 
        jusqu'à tomber sur un caractère différent ou alors la fin de mot du mot1 ou du mot2.
    
    Puis une fois sorti de la boucle on va calculer la différence des caractères (On caste les caractères
        en unsigned char car on veut les caractère qui possède aussi des accents, et si on utilise
        des char signés alors on aura pas ces caractères avec les accents car les char sont compris entre
        -127 et 127 alors que les unsigned char sont compris entre 0 et 255):

            - si la différence est positive alors le mot1 est supérieur au mot2
            - si la différence est negative alors le mot1 est inférieur au mot2
            - sinon la différence est nulle, donc les mots sont égaux

    L'ordre alphabétique est respecté par la différence des valeurs des caractères dans la table ascii
    L'ordre l'exicographique est respecté car le caractère de fin de mot est inférieur à tous les autres
        caractères, donc le mot qui n'est pas fini sera bien supérieur au mot dont on a atteint la fin
     */
    int i = 0;
    
    while (mot1[i] != '\0' && mot2[i] != '\0' && (mot1[i] == mot2[i]))
        i++;

    if ((unsigned char)mot1[i] > (unsigned char)mot2[i]) 
        return 1;
    if ((unsigned char)mot1[i] < (unsigned char)mot2[i])
        return -1;
    
    return 0;
}


char* nom_fichier(char* chemin, char* nom, char* format){

    char* nom_f = (char*) malloc(sizeof(char)*(strlen(chemin) + 
                        strlen(nom) + strlen(format) + 1));

    strcpy(nom_f, chemin);
    strcat(nom_f, nom);
    strcat(nom_f, format);

    return nom_f;
}