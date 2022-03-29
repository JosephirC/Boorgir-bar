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

        string nomIng; 
        unsigned int prixIng;
        unsigned int emplacement;
        unsigned int nbrIng;
        unsigned int cuisson;
        Temps temps(int t);

        //il faut ajouter dans le .txt un temps de cuisson


    public :

        Ingredient();

        Ingredient(const string & nomI, const unsigned int & prixI, const unsigned int & emplacementI, const unsigned int & nbrI, const unsigned int & cuissonI);

        ~Ingredient();

        bool ruptureStock(); // renvoie vraie si on a plus d'ingredients 

        void achete(/*TypeIngredient*/); // nous permet d'acheter un ingredient s'il est fini

        //void lireIngredient(const string &nom_ingredient, prix);

        void setNom(const string & nomI); //Mutateur : modifie le nom de l'ingredient

        void setPrix(const unsigned int & prixI); //Mutateur : modifie le prix de l'ingredient

        void setEmplacement(const unsigned int & emplacementI); //Mutateur : modifie l'emplacement de l'ingredient

        void setNbr(const unsigned int & nbrI); //Mutateur : modifie le nombre d'ingredient
        
        void setCuisson(const unsigned int & cuissonI); //Mutateur : modifie le temps de cuisson

        string getNom() const; //Accesseur : recupere le nom de l'ingredient 

        unsigned int getPrix() const; //Accesseur : recupere le prix de l'ingredient

        unsigned int getEmplacement() const; //Accesseur : recupere l'emplacement de l'ingredient

        unsigned int getNbr() const; //Accesseur : recupere le nombre d'ingredient

        unsigned int getCuisson() const; //Accesseur : recupere le temps de cuisson
};

#endif