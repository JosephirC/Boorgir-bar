#ifndef _COMMANDE_H
#define _COMMANDE_H

#include "Recette.h"
#include <string>
#include <iostream>

using namespace  std;

class Commande{

    private :
  
        string nomC;
        unsigned int prixC;


    public :

        Commande();

        Commande(string nom, unsigned int prix);

        ~Commande();

        string getNom() const;

        unsigned int getPrix() const;

        void chargerCarte(vector<Commande> &tabC, const string & fileCarte);

        void commandeAleatoire(vector<Commande> carte, vector<string> &commendeAl); // remplie le tableau de commande avec des recette entre 1 et 3

        unsigned int calculePrix(); // retourne le prix de la commande
};



#endif