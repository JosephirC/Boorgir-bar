#include "Temps.h"
#include "Objectif.h"
#include <string>
#include <iostream>

using namespace  std;

/** < @brief constructeur de Objectif */
Objectif::Objectif() {

}

/** < @brief destructeur de Objectif */
Objectif::~Objectif() {

}

Temps Objectif::getTemps() const{
     return T;
 }
 
void Objectif::setTemps(Temps &t){
     t=T;
} 


/** < @brief  retourne l'argent gagne pendant la partie */
 unsigned int Objectif::getArgent() const{
     return Argent;
 }


/** < @brief permet de selectionner le niveau voulu */
void Objectif::choixNiveau(unsigned int choix) {
    switch(choix)
    {
        case 1:
            T.setTemps(0.08);
            Argent=30;
            break;
        case 2:
            T.setTemps(0.5);
            Argent=70;
            break;
        case 3:
            T.setTemps(1);
            Argent=200;
            break;   
    }
}



// dans le jeu il faut faire une bouble dans la boucle cause when we finish the level we don't want to be kicked out
bool Objectif::finJeu() const{
    if ( getTemps().tempsAtteint() == true ){
        return true;
    }
    else return false;
}