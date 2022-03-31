#include "Temps.h"
#include <string>
#include "Ingredient.h"
#include <iostream>

using namespace  std;

Ingredient::Ingredient(){
    prixIng=0;
    emplacement=0;
    nbrIng=0;
    cuisson=0;
}

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

void Ingredient::setNom(const string & nomI){ //Mutateur : modifie le nom de l'ingredient
    nomIng = nomI;
} 

void Ingredient::setPrix(const unsigned int & prixI){ //Mutateur : modifie le prix de l'ingredient
    prixIng = prixI;
} 

void Ingredient::setEmplacement(const unsigned int & emplacementI){ //Mutateur : modifie l'emplacement de l'ingredient
    emplacement = emplacementI;
} 

void Ingredient::setNbr(const unsigned int & nbrI){ //Mutateur : modifie le nombre d'ingredient
    nbrIng = nbrI;
}

void Ingredient::setCuisson(const unsigned int & cuissonI){ //Mutateur : modifie le temps de cuisson
    cuisson = cuissonI;
}

string Ingredient::getNom() const{ //Accesseur : recupere le nom de l'ingredient 
    return nomIng;
} 

unsigned int Ingredient::getPrix() const{ //Accesseur : recupere le prix de l'ingredient
    return prixIng;
}

unsigned int Ingredient::getEmplacement() const{ //Accesseur : recupere l'emplacement de l'ingredient
    return emplacement;
} 

unsigned int Ingredient::getNbr() const{ //Accesseur : recupere le nombre d'ingredient
    return nbrIng;
}

unsigned int Ingredient::getCuisson() const{ //Accesseur : recupere le temps de cuisson
    return cuisson;
}