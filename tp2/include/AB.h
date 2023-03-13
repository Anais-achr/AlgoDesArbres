#ifndef AB_H
#define AB_H

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

typedef struct noeud{
    int val;
    struct noeud* fg;
    struct noeud* fd;
}Noeud, *Arbre;

/**
 * @brief alloue un noeud
 * 
 * @param val 
 * @return Arbre, adresse d'un noeud
 */
Arbre alloue_noeud(int val);

/**
 * @brief affiche un arbre en ordre prefixe
 * 
 * @param a 
 */
void affiche_arbre(Arbre a);

/**
 * @brief Calcul la hauteur d'un arbre
 * 
 * @param a 
 * @return int 
 */
int hauteur(Arbre a);

/**
 * @brief Calcul le nombre de noeud d'un arbre
 * 
 * @param a 
 * @return int 
 */
int nb_noeud(Arbre a);

/**
 * @brief Calcul le nombre de noeuds interne d'un arbre
 * 
 * @param a 
 * @return int 
 */
int nb_noeud_interne(Arbre a);

/**
 * @brief Calcul le nombre de feuilles d'un arbre
 * 
 * @param a 
 * @return int 
 */
int nb_feuille(Arbre a);

/**
 * @brief calcul le nombre de noeud interne ayant deux fils
 * 
 * @param a 
 * @return int 
 */
int nb_noeud_deux_fils(Arbre a);

/**
 * @brief Determine si un arbre est strictement bianire ou non
 * 
 * @param a 
 * @return int 
 */
int est_strictement_binaire(Arbre a);

/**
 * @brief Construit un arbre binaire à partir d'un fichier, ou un 0 représente un arbre vide
 * 
 * @param fichier 
 * @return Arbre 
 */
Arbre construit_arbre(FILE *fichier);

#endif