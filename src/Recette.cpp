#include "Recette.h"
#include <iostream>
#include <vector>

using namespace std;
/*
Recette::Recette(){
    nomRec = "";
    nbrIngRec = 0;
    prixR = 0;
    ing = NULL;
} */

/** < @brief constructeur de Recette */
Recette::Recette(const string recette, const unsigned int & nbrIngR, vector<string> tabIng, const unsigned int & prix){
    nomRec = recette;
    nbrIngRec = nbrIngR;
    for (unsigned int i=0; i<nbrIngR; i++){
        tabI.push_back(tabIng[i]);
    }
    prixR = prix;
} 

/*
Recette::~Recette(){
    if(ing!=NULL)
    {
        delete [] ing;
        ing = NULL;
    }
    prixR = 0;
}
*/

/** < @brief accesseur qui recupere le nom de la recette */
string Recette::getNom() const{ //Accesseur : recupere le nom de l'ingredient 
    return nomRec;
} 

/** < @brief accesseur qui recupere le prix de la recette */
unsigned int Recette::getPrix() const{ //Accesseur : recupere le prix de l'ingredient
    return prixR;
}


/** < @brief retourne la table d'ingredients */
const vector<string>& Recette::getTab() const{
    return tabI;
}

/** < @brief accesseur qui recupere le nombre d'ingredient dans la recette */
unsigned int Recette::getNbr() const{
    return nbrIngRec;
}
