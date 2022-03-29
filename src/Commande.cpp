#include "Jeu.h"
#include "Commande.h"
#include <iostream>

using namespace std;


Commande::Commande()
{
    tabC = NULL;
    prixC = 0;
}


Commande:: ~Commande()
{
    if(tabC != NULL)
    { 
        delete[] tabC;
        tabC = NULL;

    }
    prixC = 0;

}


 void nbrRecette()
 {


 }

 int calculePrix()
{

    return 0;

}

