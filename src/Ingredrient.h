#ifndef _INGREDIENT_H
#define _INGREDIENT_H

#include "Temps.h"
#include <string>
#include <iostream>

using namespace  std;

/*enum class TypeIngredient {
    Tomate;
    Salade;
    Burger;
    HotDog;
    PainBurger;
    PainHotdog;
    Mayo;
    Ketchup;
    Soda;
    JusOrange;
    Frite;
}*/

class Ingredient{ 

    private :

        int prixIng;
        int emplacement;
        int nbrIng;
        string nomIng;
        int cuisson;
        Temps temps;
        int ingSelectionne; // prend la valeur de l'emplacement de l'ingredient selectionner/// REMARQUE IL FAUT METTRE L EMPLACEMENT ICI 
        bool estSelectionne;
        //faire un tab statique de taille 11, chaque case contient les coordonnees x y pour chaque ingredient  dans SDL


        //il faut ajouter dans le .txt un temps de cuisson


    public :

        Ingredient();

        ~Ingredient();

        bool ruptureStock() // renvoie vraie si on a plus d'ingredients 

        void achete(/*TypeIngredient*/); // nous permet d'acheter un ingredient s'il est fini

        //void lireIngredient(const string &nom_ingredient, prix);
     
       



};

#endif