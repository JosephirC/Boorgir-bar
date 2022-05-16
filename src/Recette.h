#ifndef _RECETTE_H
#define _RECETTE_H

#include "Ingredient.h"
#include <string>
#include <iostream>
#include <vector>

using namespace  std;

class Recette{

    private :
  
        /** < @brief variable contennant le nom de la recette */ 
        string nomRec;
        /** < @brief nombre d'ingredients dans une seule recette et prix de la recette */
        int nbrIngRec, prixR; 
        //string * tabIng;
        /** < @brief tableau d'ingredients contenu dans la recette */
        vector<string> tabI;  //car c' est vect?

    public :

        //Recette();

        /** < @brief constructeur de Recette */
        Recette(const string recette, const unsigned int & nbrInR, vector<string> tabIng, const unsigned int & prix);

        /** < @brief accesseur qui recupere le nom de la recette */
        string getNom() const; 

        /** < @brief accesseur qui recupere le prix de la recette */
        unsigned int getPrix() const; 

        /** < @brief retourne la table d'ingredients */
        const vector<string>& getTab() const;
        
        /** < @brief accesseur qui recupere le nombre d'ingredient dans la recette */
        unsigned int getNbr() const;

        void affichage();


        //~Recette();

};

#endif
