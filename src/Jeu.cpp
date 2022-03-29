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


void Jeu::chargerIngredient(string ingName, const string &filename){
    Ingredient ing;
    vector<int> ingVec;
    int i;
    string nomIng = ingName;
    int prix = prixIng;
    int pos = emplacement;
    int tempsCuisson = cuisson;
    ifstream fileIng("ingredients.txt");
    
    if(fileIng.is_open()){

        //ignorer la premiere ligne
		string line;
		getline(fileIng, line);

        while(fileIng >> nomIng >> prix >> pos >> tempsCuisson){
            ingVec.push_back(nomIng);
            ingVec.push_back(prix);
            ingVec.push_back(pos);
            ingVec.push_back(tempsCuisson);
        }

        for(unsigned int i = 0; i < ingVec.size(); i++){
            cout << ingVec[i];
        }
        fileIng.close();
    }

    else 
        cout << "Failed to open file..." << endl;

    cout << "Sucess"<< endl;
}