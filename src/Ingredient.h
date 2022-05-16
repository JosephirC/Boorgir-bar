#ifndef _INGREDIENT_H
#define _INGREDIENT_H

#include "Temps.h"
#include <string>
#include <iostream>

using namespace  std;


class Ingredient{ 

    private :

        /** < @param nomIng Nom de l'ingredient */
        string nomIng; 
        /** < @param prixIng Prix de l'ingredient */
        unsigned int prixIng;
        /** < @param emplacement Emplacement de l'ingredient */
        unsigned int emplacement;
        /** < @param nbrIng Nombre d'ingredients */
        unsigned int nbrIng;
        /** < @param cuisson Temps de cuisson de certains ingredients */
        unsigned int cuisson;


    public :

        /** < @brief Constructeur de Ingredient */
        Ingredient();
        /** < @brief Constructeur de Ingredient 
         * <  @param nomI nom de l'ingredient
         * <  @param prixI prix de l'ingredient
         * <  @param emplacementI emplacement de l'ingredient
         * <  @param nbrI nombre d'ingredients
        */
        Ingredient(const string & nomI, const unsigned int & prixI, const unsigned int & emplacementI, const unsigned int & nbrI, const unsigned int & cuissonI);

        /** < @brief Mutateur : modifie le nom de l'ingredient 
         *  < @param nomI Nom de l'ingredient 
        */
        void setNom(const string & nomI); 

        /** < @brief Mutateur : modifie le prix de l'ingredient 
         *  < @param prixI : Prix de l'ingredient 
        */
        void setPrix(const unsigned int & prixI); 

        /** < @brief Mutateur : modifie l'emplacement de l'ingredient 
         * <  @param emplacementI 
        */
        void setEmplacement(const unsigned int & emplacementI); 

        /** < @brief Mutateur : modifie le nombre d'ingredient 
         * <  @param nbrI nombre d'ingredients
        */
        void setNbr(const unsigned int & nbrI); 
        
        /** < @brief Mutateur : modifie le temps de cuisson 
         * <  @param cuissonI cuisson de l'ingredient
        */
        void setCuisson(const unsigned int & cuissonI); 

        /** < @brief Accesseur : recupere le nom de l'ingredient  */
        string getNom() const; 

        /** < @brief Accesseur : recupere le prix de l'ingredient */
        unsigned int getPrix() const; 

        /** < @brief Accesseur : recupere l'emplacement de l'ingredient */
        unsigned int getEmplacement() const; 

        /** < @brief Accesseur : recupere le nombre d'ingredient */
        unsigned int getNbr() const; 

        /** < @brief Accesseur : recupere le temps de cuisson */
        unsigned int getCuisson() const;   
          
}; 


#endif