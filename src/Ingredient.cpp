#include "Temps.h"
#include <string>
#include <iostream>

using namespace  std;

Ingredient::Ingredient(){
    prixIng=0;
    emplacement=0;
    nbrIng=0;
    cuisson=0;
    ingSelectionne=0; // prend la valeur de l'emplacement de l'ingredient selectionner/// REMARQUE IL FAUT METTRE L EMPLACEMENT ICI 
    estSelectionne=FALSE;
}

Ingredient::Ingredient(const string &name, const unsigned int & price, const unsigned int & emplacement, const unsigned int & nbr, const unsigned int & cookTime){
    
}


bool Ingredient::ruptureStock(){
    return (nbrIng == 0);
}

void Ingredient::achete(){ 
    Ingredient ing;
    if(ruptureStock == true){
        nbrIng = 10;
    }
}

void setName(const string & name){ //Mutateur : modifie le nom de l'ingredient

} 

void setPrice(const unsigned int & price){ //Mutateur : modifie le prix de l'ingredient

} 

void setPosition(const unsigned int & pos){ //Mutateur : modifie l'emplacement de l'ingredient

} 

void setNumber(const unsigned int & nbr){ //Mutateur : modifie le nombre d'ingredient

}

void setTime(const unsigned int & cookTime){ //Mutateur : modifie le temps de cuisson

}

string getName() const{ //Accesseur : recupere le nom de l'ingredient 

} 

unsigned int getPrice() const{ //Accesseur : recupere le prix de l'ingredient

}

unsigned int getPosition() const{ //Accesseur : recupere l'emplacement de l'ingredient
    
} 

unsigned int getNumber() const{ //Accesseur : recupere le nombre d'ingredient

}

unsigned int getTime() const{ //Accesseur : recupere le temps de cuisson

}