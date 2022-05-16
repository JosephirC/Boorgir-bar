#include "Temps.h"
#include <string>
#include "Ingredient.h"
#include <iostream>

using namespace  std;

/** < @brief Constructeur de Ingredient */
Ingredient::Ingredient(){
    prixIng=0;
    emplacement=0;
    nbrIng=0;
    cuisson=0;
}

/** < @brief Constructeur de Ingredient 
 * <  @param nomI nom de l'ingredient
 * <  @param prixI prix de l'ingredient
 * <  @param emplacementI emplacement de l'ingredient
 * <  @param nbrI nombre d'ingredients
*/
Ingredient::Ingredient(const string & nomI, const unsigned int & prixI, const unsigned int & emplacementI, const unsigned int & nbrI, const unsigned int & cuissonI){
    nomIng = nomI;
    prixIng = prixI;
    emplacement = emplacementI;
    nbrIng = nbrI;
    cuisson = cuissonI;
}


/*bool Ingredient::ruptureStock(){
    return (nbrIng == 0);
}

void Ingredient::achete(){ 
    Ingredient ing;
    if(ruptureStock == true){
        nbrIng = 10;
    }
}*/

/** < @brief Mutateur : modifie le nom de l'ingredient
 * @param nomI Nom de l'ingredient 
*/
void Ingredient::setNom(const string & nomI){ 
    nomIng = nomI;
} 

/** < @brief Mutateur : modifie le prix de l'ingredient
 *  < @param prixI : Prix de l'ingredient
*/
void Ingredient::setPrix(const unsigned int & prixI){ 
    prixIng = prixI;
} 

/** < @brief Mutateur : modifie l'emplacement de l'ingredient */
void Ingredient::setEmplacement(const unsigned int & emplacementI){ 
    emplacement = emplacementI;
} 

/** < @brief Mutateur : modifie le nombre d'ingredient 
 * <  @param nbrI nombre d'ingredients
*/
void Ingredient::setNbr(const unsigned int & nbrI){ 
    nbrIng = nbrI;
}

/** < @brief Mutateur : modifie le temps de cuisson 
 * <  @param cuissonI cuisson de l'ingredient
*/
void Ingredient::setCuisson(const unsigned int & cuissonI){ 
    cuisson = cuissonI;
}

/** < @brief Accesseur : recupere le nom de l'ingredient  */
string Ingredient::getNom() const{ 
    return nomIng;
} 

/** < @brief Accesseur : recupere le prix de l'ingredient */
unsigned int Ingredient::getPrix() const{ 
    return prixIng;
}

/** < @brief Accesseur : recupere l'emplacement de l'ingredient */
unsigned int Ingredient::getEmplacement() const{
    return emplacement;
} 

/** < @brief Accesseur : recupere le nombre d'ingredient */
unsigned int Ingredient::getNbr() const{ 
    return nbrIng;
}

/** < @brief Accesseur : recupere le temps de cuisson */
unsigned int Ingredient::getCuisson() const{
    return cuisson;
}