#ifndef _RECETTE_H
#define _RECETTE_H

#include "Ingredient.h"
#include <string>
#include <iostream>
#include <vector>

using namespace  std;

class Recette{

    private :
  
        /** < @param nomRec Variable contennant le nom de la recette */ 
        string nomRec;
        /** < @param nbrIngRec Nombre d'ingredients dans une seule recette et prix de la recette 
         *  < @param prixR */
        int nbrIngRec, prixR; 
        /** < @param tabI Tableau d'ingredients contenu dans la recette */
        vector<string> tabI;  

    public :

        //Recette();

        /** < @brief Constructeur de Recette 
         * <  @param recette recette
         * <  @param nbrIngR nombre d'ingredients dans la recette
         * <  @param tabIng tableau d'ingredients
         * <  @param prix prix de la recette
        */
        Recette(const string recette, const unsigned int & nbrInR, vector<string> tabIng, const unsigned int & prix);

        /** < @brief Accesseur : recupere le nom de la recette */
        string getNom() const; 

        /** < @brief Accesseur : recupere le prix de la recette */
        unsigned int getPrix() const; 

        /** < @brief Accesseur : recupere la table d'ingredients */
        const vector<string>& getTab() const;
        
        /** < @brief Accesseur : recupere le nombre d'ingredient dans la recette */
        unsigned int getNbr() const;

};

#endif
