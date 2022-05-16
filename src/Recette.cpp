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

/** < @brief Constructeur de Recette 
 * <  @param recette recette
 * <  @param nbrIngR nombre d'ingredients dans la recette
 * <  @param tabIng tableau d'ingredients
 * <  @param prix prix de la recette
*/
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

/** < @brief Accesseur : recupere le nom de la recette */
string Recette::getNom() const{
    return nomRec;
} 

/** < @brief Accesseur : recupere le prix de la recette */
unsigned int Recette::getPrix() const{ 
    return prixR;
}


/** < @brief Accesseur : recupere la table d'ingredients */
const vector<string>& Recette::getTab() const{
    return tabI;
}

/** < @brief Accesseur : recupere le nombre d'ingredient dans la recette */
unsigned int Recette::getNbr() const{
    return nbrIngRec;
}
