#ifndef _JEU_H
#define _JEU_H


#include <string>
#include <iostream>

using namespace  std;

enum class TypeNiveau {
    Facile;
    Difficile;
    Crazy;
}

class Jeu{

    private :

        Client *tabC;
        Temps tempsJ;
        Ingredient tabIng[50];
        Recette tabRec[50];
        int objectif; 
        int additionArgent;  // additionArgent = tabC[i].paiement;

    public :

        Jeu();

        Jeu(int typeJeu, int niveau); // il faut lire un fichier .txt qui contient les niveau avec le nbr de client / temps en parametres dans le constructur avec un ifstream

        ~Jeu();

        void chargerIngredient(*tabIng, const string& nom_ingredient;

        void chargerRecette(tabR, const string& nom_recette);



};

#endif