#include "ensemble.h"
#include <stdio.h>
#include <stdlib.h>

/* encode une adresse IP sous la forme d'un entier 32bits*/
long int encode_ip(char *ip) {
    unsigned char b1, b2, b3, b4;
    long int res;
    if (sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &b1, &b2, &b3, &b4) == 4) {
        res = b1;
        res = 256 * res + b2;
        res = 256 * res + b3;
        res = 256 * res + b4;
        return res;
    }
    // on suppose ici que 255.255.255.255 n'est pas une adresse valide
    return -1;
}


int main(int argc, char *argv[]) {
    FILE *df = NULL;
    Ensemble *ens = NULL;
    char ip[16];

    // On s'assure d'avoir un argument dans la ligne de commande
    if (argc != 2) {
        fprintf(stderr, "usage : %s <fichier à lire>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // On tente d'ouvrir le fichier de chemin le premier argument
    df = fopen(argv[1], "r");
    if (df == NULL) {
        fprintf(stderr, "impossible d'ouvrir %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    ens = cree_ensemble();
    if (ens == NULL) {
        fprintf(stderr, "erreur lors de la création de l'ensemble\n");
        fclose(df);
        return EXIT_FAILURE;
    }

    // Pour chaque ip dans le fichier
    while (fscanf(df, "%*d %15s", ip) == 1) { // on jette le timestamp avec %*d
        long int n = encode_ip(ip);
        // on passe si l'adresse n'a pu être traduite
        if (n < 0)
            continue;

        // on l'ajoute à l'ensemble `ens`
        if (ajoute(ens, n) < 0) {
            // on quitte la boucle en cas d'échec
            fprintf(stderr, "erreur lors de l'ajout de %s (%08lx)\n", ip, n);
            break;
        }
    }
    fclose(df);
    df = NULL;

    printf("trouvé %d ip différentes\n", taille(ens));

    detruit_ensemble(ens);
    ens = NULL;

    return 0;
}