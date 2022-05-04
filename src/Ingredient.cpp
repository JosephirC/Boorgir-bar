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

/** < @brief muutateur qui modifie le nom de l'ingredient */
void Ingredient::setNom(const string & nomI){ //Mutateur : modifie le nom de l'ingredient
    nomIng = nomI;
} 

/** < @brief mutateur qui modifie le prix de l'ingredient */
void Ingredient::setPrix(const unsigned int & prixI){ //Mutateur : modifie le prix de l'ingredient
    prixIng = prixI;
} 

/** < @brief mutateur qui modifie l'emplacement de l'ingredient */
void Ingredient::setEmplacement(const unsigned int & emplacementI){ //Mutateur : modifie l'emplacement de l'ingredient
    emplacement = emplacementI;
} 

/** < @brief mutateur qui modifie le nombre d'ingredient */
void Ingredient::setNbr(const unsigned int & nbrI){ //Mutateur : modifie le nombre d'ingredient
    nbrIng = nbrI;
}

/** < @brief mutateur qui modifie le temps de cuisson */
void Ingredient::setCuisson(const unsigned int & cuissonI){ //Mutateur : modifie le temps de cuisson
    cuisson = cuissonI;
}

/** < @brief accesseur qui recupere le nom de l'ingredient  */
string Ingredient::getNom() const{ //Accesseur : recupere le nom de l'ingredient 
    return nomIng;
} 

/** < @brief accesseur qui recupere le prix de l'ingredient */
unsigned int Ingredient::getPrix() const{ //Accesseur : recupere le prix de l'ingredient
    return prixIng;
}

/** < @brief accesseur qui recupere l'emplacement de l'ingredient */
unsigned int Ingredient::getEmplacement() const{ //Accesseur : recupere l'emplacement de l'ingredient
    return emplacement;
} 

/** < @brief accesseur qui recupere le nombre d'ingredient */
unsigned int Ingredient::getNbr() const{ //Accesseur : recupere le nombre d'ingredient
    return nbrIng;
}

/** < @brief accesseur qui recupere le temps de cuisson */
unsigned int Ingredient::getCuisson() const{ //Accesseur : recupere le temps de cuisson
    return cuisson;
}