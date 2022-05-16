#include "Jeu.h"
#include "Commande.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


/** < @brief un constructeur de Commande */
Commande::Commande()
{
    nomC = " ";
    prixC = 0;
}

/** < @brief un constructeur de Commande */
Commande::Commande(string nom, unsigned int prix){
    nomC = nom;
    prixC = prix;
}

/** < @brief le destructeur de Commande */
Commande:: ~Commande(){   
    
}

/** < @brief mutateur de Commande */
void Commande::setNom(const string & nom){
    nomC = nom;
}

/** < @brief mutateur de Commande */ 
void Commande::setPrix(const unsigned int & prix){
    prixC = prix;
}

/** < @brief retourne le nom de la commande */
string Commande::getNom() const{
    return nomC;
}

/** < @brief fonction qui retourne le prix de la commande */
unsigned int Commande::getPrix() const{
    return prixC;    
}

