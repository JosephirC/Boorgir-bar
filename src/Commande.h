#ifndef _COMMANDE_H
#define _COMMANDE_H

#include "Recette.h"
#include <string>
#include <iostream>

using namespace  std;

class Commande{

    private :
  
        /** < @brief varaible contenant le nom de la commande */
        string nomC;
        /** < @brief  prix de la commande */
        unsigned int prixC;


    public :

        /** < @brief un constructeur de Commande */
        Commande();
        /** < @brief un constructeur de Commande */
        Commande(string nom, unsigned int prix);
        /** < @brief le destructeur de Commande */
        ~Commande();

        /** < @brief mutateur de Commande */
        void setNom(const string &nom);
        /** < @brief mutateur de Commande */
        void setPrix(const unsigned int & prix);

        /** < @brief retourne le nom de la commande */ 
        string getNom() const;
        /** < @brief fonction qui retourne le prix de la commande */
        unsigned int getPrix() const;

        /** < @brief garec au fichier txt, on charge le menu du jour */
        void chargerCarte(vector<Commande> & tabC, const string & fileCarte);
        /** < @brief, choisi des recettes aleatoire du menu pour le donner au client */
        void commandeAleatoire(const vector<Commande> & carte, vector<Commande> & commendeAl); // remplie le tableau de commande avec des recette entre 1 et 3

        /** < @brief fonction qui calcule le prix que le client doit payer */
        void calculePrix(vector<Commande> &commandeAl, unsigned int & prix); // retourne le prix de la commande
};

#endif