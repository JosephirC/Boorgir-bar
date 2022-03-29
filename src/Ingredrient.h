Afficher plus
Ingredient.cpp2 Ko

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
        Temps temps;

        //il faut ajouter dans le .txt un temps de cuisson


    public :

        Ingredient();

        Ingredient(const string &name, const unsigned int & price, const unsigned int & emplacement, const unsigned int & nbr, const unsigned int & cookTime);

        ~Ingredient();

        bool ruptureStock(); // renvoie vraie si on a plus d'ingredients 

        void achete(/*TypeIngredient*/); // nous permet d'acheter un ingredient s'il est fini

        //void lireIngredient(const string &nom_ingredient, prix);

        void setName(const string & name); //Mutateur : modifie le nom de l'ingredient

        void setPrice(const unsigned int & price); //Mutateur : modifie le prix de l'ingredient

        void setPosition(const unsigned int & pos); //Mutateur : modifie l'emplacement de l'ingredient

        void setNumber(const unsigned int & nbr); //Mutateur : modifie le nombre d'ingredient
        
        void setTime(const unsigned int & cookTime); //Mutateur : modifie le temps de cuisson

        string getName() const; //Accesseur : recupere le nom de l'ingredient 

        unsigned int getPrice() const; //Accesseur : recupere le prix de l'ingredient

        unsigned int getPosition() const; //Accesseur : recupere l'emplacement de l'ingredient

        unsigned int getNumber() const; //Accesseur : recupere le nombre d'ingredient

        unsigned int getTime() const; //Accesseur : recupere le temps de cuisson
};

#endif