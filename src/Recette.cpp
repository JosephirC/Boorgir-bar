#include "Recette.h"
#include <iostream>

using namespace std;

Recette::Recette(){
    nomRec = "";
    nbrIngRec = 0;
    prixR = 0;
    ing = NULL;
}

Recette::Recette(string recette){
    nomRec = recette;
} 

Recette::~Recette(){
    if(ing!=NULL)
    {
        delete [] ing;
        ing = NULL;
    }
    prixR = 0;
}





