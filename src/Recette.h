#ifndef _RECETTE_H
#define _RECETTE_H

#include "Ingredient.h"
#include <string>
#include <iostream>

using namespace  std;

class Recette{

    private :
  
        string nomRec;
        int nbrIngRec, prixR; // nombre d'ingredient dans une seule recette et prix de la recette
        Ingredient * ing;

    public :

        Recette();

        Recette(string recette);

        ~Recette();

};

#endif