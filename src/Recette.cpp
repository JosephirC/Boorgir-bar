#include "Recette.h"
#include <iostream>

using namespace std;

Recette::Recette (string nomRec){
    ing = NULL;
    prixR = 0;
}

Recette::~Recette(){
    if(ing!=NULL)
    {
        delete [] ing;
        ing = NULL;
    }
    prixR = 0;
}



