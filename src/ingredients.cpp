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

