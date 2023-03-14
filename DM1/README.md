# DM - Filtrage d’un texte
Dans ce DM, on se propose d’implémenter des arbres binaires de recherche de chaines de caractères, dans
le but de trouver tous les mots d’un texte qui ne sont pas déjà présent dans un autre texte.

## Installation
```make``` ou  ```make filtre```


## Exemple d'execution
```./filtre -v textes/texte1.txt textes/texte2.txt```

## Option
l'option ```-v``` permet de créer quatre fichiers .pdf et .dot contenant une représentation
visuelle des ABR construits. Ces fichiers seront dans le dossier ./arbre_dot


## Tests
un fichier ```test_ABR.c```est disponible.
### Installation 
```make test_ABR```
### Exemple d'éxecution 
```./test_ABR textes/texte1.txt```


## Clean
### Supprimer les executables et les fichiers objets 
```make clean```
### Supprimer les fichiers .pdf et .dot créés dans le dossier arbre_dot
```rm -f arbre_dot/dot/*.dot arbre_dot/pdf/*.pdf```

