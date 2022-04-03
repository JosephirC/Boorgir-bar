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

string Recette::getNom() const{ //Accesseur : recupere le nom de l'ingredient 
    return nomRec;
} 

unsigned int Recette::getPrix() const{ //Accesseur : recupere le prix de l'ingredient
    return prixR;
}


const vector<string>& Recette::getTab() const{
    return tabI;
}

unsigned int Recette::getNbr() const{
    return nbrIngRec;
}
