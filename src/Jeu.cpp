#include "Jeu.h"
#include "Recette.h"
#include "Ingredient.h"
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
     
ostream &operator<< (ostream & flux, const Ingredient &ing){
    flux << "Nom : " << ing.getNom() << " | Prix : " << ing.getPrix() << "$ | Emplacement : " << ing.getEmplacement() << " | Temps de cuisson : " << ing.getCuisson() << " sec"  << endl; 
    return flux;
}

void Jeu::chargerIngredient(const string &filenameIng){
    vector<Ingredient> ingVec;
    ifstream fileIng(filenameIng.c_str());
    string nomIng;
    int prix, pos, tempsCuisson;
    if(fileIng.is_open()){

        //Pour ignorer la premiere ligne
		string line;
		getline(fileIng, line);

        while(fileIng >> nomIng >> prix >> pos >> tempsCuisson){
            Ingredient ing(nomIng, prix, pos, 10, tempsCuisson);
            ingVec.push_back(ing);
            cout << nomIng << " " << prix << " " << pos << " " << tempsCuisson << endl;
        }

        for(unsigned int i = 0; i < ingVec.size(); i++){
            cout << ingVec[i] << endl;
        }
        fileIng.close();
    }

    else 
        cout << "Failed to open file..." << endl;
}

void Jeu::chargerRecette(const string &filenameRec){
    vector<Recette> recVec;
    vector<Ingredient> ingRecVec;
    ifstream fileRec(filenameRec.c_str());
    string nom;
    int nbr, prix;

    

    if(fileRec.is_open()){

        while(fileRec >> nom >> nbr >> ingRecVec >> prix)

        fileRec.close();
    }

}
