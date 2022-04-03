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
    vector<Ingredient> tabI;
    vector<Recette> tabR;
    vector<Commande> tabC;
    vector<string> commande;
    Jeu j1(0,0);
    //j1.chargerIngredient(tabI, "./txt/Ingredients.txt");
    //j1.chargerRecette(tabR, "./txt/Recette.txt");
    Commande c;
    c.commandeAleatoire(tabC, commande);

}
