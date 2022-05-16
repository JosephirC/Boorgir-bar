#include "Jeu.h"
#include "Commande.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


/** < @brief Constructeur de Commande */
Commande::Commande()
{
    nomC = " ";
    prixC = 0;
}

/** < @brief Constructeur de Commande 
 * @param nom nom de la commande
 * @param prix prix de la commande
*/
Commande::Commande(string nom, unsigned int prix){
    nomC = nom;
    prixC = prix;
}

/** < @brief Destructeur de Commande */
Commande:: ~Commande(){   
    
}

/** < @brief Mutateur : recupere le nom 
 * @param nom nom de la commande
*/
void Commande::setNom(const string & nom){
    nomC = nom;
}

/** < @brief Mutateur : recupere le prix 
 * @param prix prix de la commande
*/
void Commande::setPrix(const unsigned int & prix){
    prixC = prix;
}

/** < @brief Accesseur : modifie le nom */ 
string Commande::getNom() const{
    return nomC;
}

/** < @brief Accesseur : modifie le prix */
unsigned int Commande::getPrix() const{
    return prixC;    
}

