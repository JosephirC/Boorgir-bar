#ifndef _RECETTE_H
#define _RECETTE_H

#include "Ingredrient.h"
#include <string>
#include <iostream>

using namespace  std;

enum class TypeRecette {
    Burger_Ketchup;
    Burger_Mayo;
    HotDog_Ketchup;
    HotDog_Mayo;
    Soda;
    JusOrange;
    Frite;
}

class Recette{

    private :
  
        Ingredient ing[50];
        string nomRec;
        int prixR;

    public :

        Recette();

        ~Recette();

        //void lireRecette(tab, const string &nom_recette, prixR);
         //Idee : Apres avoir appeler lireRecette(), est ce que je dois avoir un tableau calcul[] et puis dans une boucle durant chaque iteration je stocke le prix de chaque recette (i=0, i=1, i=2, etc)

        //int calculePrix(/*tabIng[j]*/); // retourne le prix d'une seule recette 
        ^
        |

       // c'est pas la peine, on le met directement dans le .txt

};

#endif