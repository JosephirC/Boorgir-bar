#ifndef _COMMANDE_H
#define _COMMANDE_H

#include "Recette.h"
#include <string>
#include <iostream>

using namespace  std;

class Commande{

    private :
  
        Recette * tabC;
        int prixC;


    public :

        Commande();

        ~Commande();

        void nbrRecette(); // remplie le tableau de commande avec des recette entre 1 et 3

        int calculePrix(); // retourne le prix de la commande
        
};

#endif