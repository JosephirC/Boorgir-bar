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
    srand(time(NULL));
    unsigned int prix;
    vector<Ingredient> tabI;
    vector<Recette> tabR;
    vector<Commande> tabC;
    vector<Commande> commande;
    vector<Client> cli;
    Jeu j1(0,0);
    //j1.chargerIngredient(tabI, "./txt/Ingredients.txt");
    //j1.chargerRecette(tabR, "./txt/Recette.txt");
    Commande c;
    //c.commandeAleatoire(tabC, commande);
    //c.calculePrix(commande, prix);
    j1.creationClient(4,cli);

    //j1.compareRecette(tabR);
    //j1.creationRecette("B_Steak");
    unsigned int IdCl;
    //j1.compareRecette(tabR, cli, "Frites", IdCl);
    j1.effaceRecette(cli, IdCl);
}
