#ifndef _JEU_H
#define _JEU_H

#include "Ingredient.h"
#include "Recette.h"
#include "Client.h"
#include "Temps.h"
#include <vector>
#include <iostream>

using namespace  std;

/*enum class TypeNiveau {
    Facile;
    Difficile;
    Crazy;
}*/

class Jeu{

    private :

        Client *tabC;
        Temps tempsJ(int periode);
        vector<Ingredient> tabIng; //[50]
        vector<Recette> tabRec; //[50]
        int objectif; 
        int additionArgent;  // additionArgent = tabC[i].paiement;
        int ingSelectionne; // prend la valeur de l'emplacement de l'ingredient selectionner/// REMARQUE IL FAUT METTRE L EMPLACEMENT ICI 
        bool estSelectionne;
        //faire un tab statique de taille 11, chaque case contient les coordonnees x y pour chaque ingredient  dans SDL


    public :

        Jeu();

        Jeu(int typeJeu, int niveau); // il faut lire un fichier .txt qui contient les niveau avec le nbr de client / temps en parametres dans le constructur avec un ifstream

        ~Jeu();

        //void chargerIngredient(Ingredient *tabIng, const string& nom_ingredient);
        void chargerIngredient(const string& filename);


        void chargerRecette(const string& nom_recette);


        const vector<Recette>& getvector() const {return tabRec;}
        void setvector(vector<Recette> vec){tabRec = vec;}

        



};

#endif