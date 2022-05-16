#include "Temps.h"
#include <string>
#include "Ingredient.h"
#include <iostream>

using namespace  std;

/** < @brief un constructeur de Ingredient */
Ingredient::Ingredient(){
    prixIng=0;
    emplacement=0;
    nbrIng=0;
    cuisson=0;
}

/** < @brief un constructeur de Ingredient */
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

/** < @brief Muutateur : modifie le nom de l'ingredient 
 * @param nomI : Nom de l'ingredient
*/
void Ingredient::setNom(const string & nomI){ 
    nomIng = nomI;
} 

/** < @brief Mutateur : modifie le prix de l'ingredient 
 * * @param prixI : Prix de l'ingredient
*/
void Ingredient::setPrix(const unsigned int & prixI){ 
    prixIng = prixI;
} 

/** < @brief Mutateur : qui modifie l'emplacement de l'ingredient */
void Ingredient::setEmplacement(const unsigned int & emplacementI){ 
    emplacement = emplacementI;
} 

/** < @brief Mutateur : qui modifie le nombre d'ingredient */
void Ingredient::setNbr(const unsigned int & nbrI){ 
    nbrIng = nbrI;
}

/** < @brief Mutateur : qui modifie le temps de cuisson */
void Ingredient::setCuisson(const unsigned int & cuissonI){ 
    cuisson = cuissonI;
}

/** < @brief Accesseur : qui recupere le nom de l'ingredient  */
string Ingredient::getNom() const{ 
    return nomIng;
} 

/** < @brief Accesseur : qui recupere le prix de l'ingredient */
unsigned int Ingredient::getPrix() const{ //Accesseur : recupere le prix de l'ingredient
    return prixIng;
}

/** < @brief Accesseur : qui recupere l'emplacement de l'ingredient */
unsigned int Ingredient::getEmplacement() const{ //Accesseur : recupere l'emplacement de l'ingredient
    return emplacement;
} 

/** < @brief Accesseur : qui recupere le nombre d'ingredient */
unsigned int Ingredient::getNbr() const{ //Accesseur : recupere le nombre d'ingredient
    return nbrIng;
}

/** < @brief Accesseur : qui recupere le temps de cuisson */
unsigned int Ingredient::getCuisson() const{ //Accesseur : recupere le temps de cuisson
    return cuisson;
}