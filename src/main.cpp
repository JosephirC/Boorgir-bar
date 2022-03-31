#include "Jeu.h"
//#include "Recette.h"
//#include "Ingredient.h"
//#include "Client.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    Jeu j1(0,0);
    //string ingredient = "Salade";
    j1.chargerIngredient("./txt/Ingredient.md");
    

}