#ifndef _RECETTE_H
#define _RECETTE_H

#include "Ingredient.h"
#include <string>
#include <iostream>
#include <vector>

using namespace  std;

class Recette{

    private :
  
        string nomRec;
        int nbrIngRec, prixR; // nombre d'ingredient dans une seule recette et prix de la recette
        //string * tabIng;
        vector<string> tabI;  //car c' est vect?

    public :

        //Recette();

        Recette(const string recette, const unsigned int & nbrInR, vector<string> tabIng, const unsigned int & prix);

        string getNom() const; //Accesseur : recupere le nom de la recette 

        unsigned int getPrix() const; //Accesseur : recupere le prix de la recette

        const vector<string>& getTab() const;
        
        unsigned int getNbr() const; //Accesseur : recupere le nombre d'ingredient dans la recette

        void affichage();


        //~Recette();

};

#endif
