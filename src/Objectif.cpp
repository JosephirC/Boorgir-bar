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

/*
double Objectif::getTemps() const{
     return Temp;
 }
 
void Objectif::setTemps(Temps &t){

     t=Temp;
 } 
*/

/** < @brief  retourne l'argent gagne pendant la partie */
 unsigned int Objectif::getArgent() const{
     return Argent;
 }


/** < @brief permet de selectionner le niveau voulu */
void Objectif::choixNiveau(int choix) {
    switch(choix)
    {
        case 1:
            Temp.setTemps(3);
            Argent=300;
            break;
        case 2:
            Temp.setTemps(3);
            Argent=400;
            break;
        case 3:
            Temp.setTemps(2);
            Argent=400;
            break;   
    }
}

// dans le jeu il faut faire une bouble dans la boucle cause when we finish the level we don't want to be kicked out
bool Objectif::finJeu() const{
    Temps objTemp(Temp);
    bool retour=false;
    if ( objTemp.tempsAtteint() == true ){
        cout<< "TRUE"; 
    }
    else cout << "FALSE";
    cout<< objTemp.tempsRestant() << "  "<<endl;
    return retour;
}