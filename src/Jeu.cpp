#include "Jeu.h"
#include "Recette.h"
#include "Client.h"
#include "Temps.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

Jeu::Jeu(){

}

Jeu::Jeu(int typeJeu, int niveau){

}

Jeu::~Jeu(){

}

/*void Jeu::chargerIngredient(tabIng, string ingName, const string &filename){
    nomIng = ingName;
    vector<int> ingVec;
}*/

/*
void Jeu::chargerIngredient(const string &filename){
    vector<Ingredient> ingVec;
    Ingredient ing;
//    vector<int> ingVec;                   //cause  ??
    string nomIng = ing.getNom();
    int prix = ing.getPrix();
    int pos = ing.getEmplacement();
    int tempsCuisson = ing.getCuisson();

    ifstream fileIng("ingredients.txt");
    if(fileIng.is_open()){

        //ignorer la premiere ligne
		string line;
		getline(fileIng, line);

        while(fileIng >> nomIng >> prix >> pos >> tempsCuisson){
            Ingredient ing(nomIng, prix, pos, 10, tempsCuisson);
            ingVec.push_back(ing);
        }

        for(unsigned int i = 0; i < ingVec.size(); i++){
            cout << ingVec[i];
        }
        fileIng.close();
    }

    else 
        cout << "Failed to open file..." << endl;

    cout << "Sucess"<< endl;
}*/