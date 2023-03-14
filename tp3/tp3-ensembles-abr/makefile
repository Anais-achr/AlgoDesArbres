# Fichier de règles de compilation (plus de détails en perfectionnement C)
# 
# Pour compiler une variante d'implémentation d'ensemble
# lancer : make nom_de_variante. 
# Ex:
#     make tab_non_trie
# ou
#     make lst

CODEDIR = .

VISITE = $(CODEDIR)/visites_uniques
ENSEMBLE = $(CODEDIR)/ensemble
VARIANTS = tab_non_trie lst tab_trie
TARGETS = $(addprefix $(VISITE)_, $(VARIANTS))

CFLAGS = -std=c17 -Wall -g

all: tab_non_trie lst tab_trie abr

lst: visites_uniques_lst
tab_trie: visites_uniques_tab_trie
tab_non_trie: visites_uniques_tab_non_trie
abr: visites_uniques_abr

$(VISITE)_%: $(ENSEMBLE)_%.o $(VISITE).o
	$(CC) $(LDFLAGS) $^ -o $@

$(VISITE).o: $(VISITE).c $(ENSEMBLE).h
$(ENSEMBLE)_%.o: $(ENSEMBLE)_%.c $(ENSEMBLE).h

.PHONY: clean

clean:
	$(RM) *.o $(TARGETS)
