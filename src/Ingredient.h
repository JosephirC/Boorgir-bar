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

        /** < @brief nom de l'ingredient */
        string nomIng; 
        /** < @brief prix de l'ingredient */
        unsigned int prixIng;
        /** < @brief emplacement de l'ingredient */
        unsigned int emplacement;
        /** < @brief nombre d'ingredients */
        unsigned int nbrIng;
        /** < @brief temps de cuisson de certains ingredients */
        unsigned int cuisson;
        //Temps temps(int t);

        //il faut ajouter dans le .txt un temps de cuisson


    public :

        /** < @brief un constructeur de Ingredient */
        Ingredient();
        /** < @brief un constructeur de Ingredient */
        Ingredient(const string & nomI, const unsigned int & prixI, const unsigned int & emplacementI, const unsigned int & nbrI, const unsigned int & cuissonI);

        // ~Ingredient();

        /** < @brief renvoie vraie si on a plus d'ingredients  */
        bool ruptureStock(); 

        /** < @brief acheter un ingredient s'il y en a plus en stock */
        void achete(/*TypeIngredient*/);

        //void lireIngredient(const string &nom_ingredient, prix);

        /** < @brief muutateur qui modifie le nom de l'ingredient */
        void setNom(const string & nomI); 

        /** < @brief mutateur qui modifie le prix de l'ingredient */
        void setPrix(const unsigned int & prixI); 

        /** < @brief mutateur qui modifie l'emplacement de l'ingredient */
        void setEmplacement(const unsigned int & emplacementI); 

        /** < @brief mutateur qui modifie le nombre d'ingredient */
        void setNbr(const unsigned int & nbrI); 
        
        /** < @brief mutateur qui modifie le temps de cuisson */
        void setCuisson(const unsigned int & cuissonI); 

        /** < @brief accesseur qui recupere le nom de l'ingredient  */
        string getNom() const; 

        /** < @brief accesseur qui recupere le prix de l'ingredient */
        unsigned int getPrix() const; 

        /** < @brief accesseur qui recupere l'emplacement de l'ingredient */
        unsigned int getEmplacement() const; 

        /** < @brief accesseur qui recupere le nombre d'ingredient */
        unsigned int getNbr() const; 

        /** < @brief accesseur qui recupere le temps de cuisson */
        unsigned int getCuisson() const;     
}; 

//ostream &operator<< (ostream & flux, const Ingredient &ing);

#endif