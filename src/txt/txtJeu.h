#ifndef _TXTJEU_H
#define _TXTJEU_H

#include "../Jeu.h"

void affCarte(vector <Commande> carte);
void affRecette(vector<Recette> tabRec);
void txtBoucle (Jeu & j, vector<Recette> &R);
void affIng(vector<Ingredient> tabIng);

#endif
