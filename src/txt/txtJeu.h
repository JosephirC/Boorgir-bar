#ifndef _TXTJEU_H
#define _TXTJEU_H

#include "../Jeu.h"

/** < @brief permet d'afficher la carte */
void affCarte(vector <Commande> carte);

/** < @brief affiche la recette d'une commande */
void affRecette(vector<Recette> tabRec);

/** < @brief  */
void txtBoucle (Jeu & j, vector<Recette> &R);

void txtBoucleAcc (Jeu & j);

/** < @brief affiche les ingredients */
void affIng(vector<Ingredient> tabIng);

#endif
