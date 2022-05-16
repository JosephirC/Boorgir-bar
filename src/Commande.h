#ifndef _COMMANDE_H
#define _COMMANDE_H

#include "Recette.h"
#include <string>
#include <iostream>

using namespace  std;

class Commande{

    private :
  
        /** < @param nomC varaible contenant le nom de la commande */
        string nomC;
        /** < @param prixC  prix de la commande */
        unsigned int prixC;


    public :

        /** < @brief Constructeur de Commande */
        Commande();
        /** < @brief Constructeur de Commande 
         * @param nom nom de la commande
         * @param prix prix de la commande
        */
        Commande(string nom, unsigned int prix);
        /** < @brief Destructeur de Commande */
        ~Commande();

        /** < @brief Mutateur : modifie le nom 
         * @param nom nom de la commande
        */
        void setNom(const string &nom);
        /** < @brief Mutateur : modifie le prix 
         * @param prix prix de la commande
        */
        void setPrix(const unsigned int & prix);

        /** < @brief Accesseur : recupere le nom */ 
        string getNom() const;
        /** < @brief Accesseur : recupere le prix */
        unsigned int getPrix() const;
        
};

#endif