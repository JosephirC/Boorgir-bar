#ifndef _TXTJEU_H
#define _TXTJEU_H

#include "../Jeu.h"


/** < @brief Corps du jeu 
 * < @param j jeu
 * < @param ok booleen qui fait sortir de la boucle
*/
void txtBoucle (Jeu & j,bool &ok);
/** < @brief Acceuil du jeu 
 * < @param j jeu
 * < @param ok booleen qui fait sortir de la boucle
*/
void txtBoucleAcc (Jeu & j,bool &ok);
/** < @brief Fin du jeu 
 * < @param j jeu
 * < @param g message pour savoir si on a gagne ou perdue
 * < @param ok booleen qui fait sortir de la boucle
*/
void txtBoucleFin(Jeu &jeu,string g, bool &ok);

/** < @brief Boucle qui le jeu en boucle 
 * < @param j jeu
*/
void boucleJeu(Jeu & j);

#endif
