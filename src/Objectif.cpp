#include "Temps.h"
#include "Objectif.h"
#include <string>
#include <iostream>

using namespace  std;

/** < @brief Constructeur de Objectif */
Objectif::Objectif() {

}

/** < @brief Destructeur de Objectif */
Objectif::~Objectif() {

}

/** < @brief Accesseur : recupere le temps */
Temps Objectif::getTemps() const{
     return T;
 }
 
/** < @brief Mutateur : modifie le temps 
 *  @param t temps du jeu
*/
void Objectif::setTemps(Temps &t){
     t=T;
} 


/** < @brief Accesseur : recupere l'argent gagne pendant la partie */
 unsigned int Objectif::getArgent() const{
     return Argent;
 }

/** < @brief Permet de selectionner le niveau voulu
 *  @param choix choisir le niveau de difficulte
 */
void Objectif::choixNiveau(unsigned int choix) {
    switch(choix)
    {
        case 1:
            T.setTemps(0.02);
            Argent=30;
            break;
        case 2:
            T.setTemps(0.5);
            Argent=70;
            break;
        case 3:
            T.setTemps(1);
            Argent=250;
            break;   
    }
}


/** < @brief Permet d'arreter la partie */
bool Objectif::finJeu() const{
    if ( getTemps().tempsAtteint() == true ){
        cout<< getTemps().tempsAtteint();
        return true;
    }
    else return false;
}