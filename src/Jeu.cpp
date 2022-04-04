#include "Jeu.h"
#include "Recette.h"
#include "Ingredient.h"
#include "Commande.h"
#include "Client.h"
#include "Temps.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

Jeu::Jeu(){

}

Jeu::Jeu(int typeJeu, int niveau){

}


Jeu::~Jeu(){
    
}

/*
const vector<Commande>& Jeu::getCarte() const {
    return carte;
}

void Jeu::setCarte(vector<Commande> cart){
    carte = cart;
}
*/

     
ostream &operator<< (ostream & flux, const Ingredient &ing){
    flux << "Nom : " << ing.getNom() << " | Prix : " << ing.getPrix() << "$ | Emplacement : " << ing.getEmplacement() << " | Temps de cuisson : " << ing.getCuisson() << " sec"  << endl; 
    return flux;
}

ostream &operator<< (ostream & flux, const Recette &rec){
    flux << "Nom : " << rec.getNom() 
            << " | Prix : " << rec.getPrix()
                << "$ | Ingredient : ";
    for(unsigned int i=0;i<rec.getNbr();i++){
        flux <<rec.getTab()[i] << " ";
    }
    flux << endl; 
    return flux;
}


void Jeu::chargerIngredient(vector<Ingredient> &ingVec, const string &filenameIng){
    //vector<Ingredient> ingVec;
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
            //cout << nomIng << " " << prix << " " << pos << " " << tempsCuisson << endl;
        }
        
        cout << "----------Voici tous les Ingredients----------" << endl << endl;

        for(unsigned int i = 0; i < ingVec.size(); i++){
            cout << ingVec[i] << endl;
        }

        fileIng.close();
    }

    else 
        cout << "Failed to open file..." << endl;
}

void Jeu::chargerRecette(vector<Recette> &recVec, const string &filenameRec){
    //vector<Recette> recVec;
    //vector<Ingredient> ingRecVec;             //pour mettre Ingredients
    ifstream fileRec(filenameRec.c_str());
    string nom,nomI,line;
    int nbr, prix;
    vector<string> nomIngRec; //car nom
    istringstream iss;

    if(fileRec.is_open()){
        while(!fileRec.eof()){
            getline(fileRec, line);
            if (fileRec.good()){
                iss.clear();
                iss.str(line);
                while (iss.good()){
                    iss >> nom; 
                    iss >> nbr;
                    //cout << nbr << " " << typeid(nbr).name() << " no? " << endl;
                    for (int i=0 ;i<nbr;i++){
                        iss >>nomI;
                        //cout<<nomI<<i<<endl;
                        nomIngRec.push_back(nomI);
                    }
                    iss >> prix;
                    //cout << nom <<" "<<nbr<<" "<<prix<<endl;
                    Recette Rec(nom,nbr,nomIngRec,prix);
                    recVec.push_back(Rec);
                    nomIngRec.clear();

                }
            }
        }

        cout << "----------Voici les Recettes----------" << endl << endl;

        for(unsigned int i = 0; i < recVec.size(); i++){
            cout << recVec[i] << endl;
        }

        fileRec.close();

    }
    else
        cout << "Failed to open file..." << endl;
    
}





void Jeu::creationClient(const unsigned int &I){

    Commande com;
    vector<Commande> comAl;
    unsigned int i;
    for(i=0;i<I;i++){
        int prix = com.calculePrix(comAl);
        Client cli(i+1,com,prix);
        tabC.push_back(cli);
        comAl.clear();
    }
    
    /*
    for (int j=0;j<4;j++){
        cout << tabC[j].getPrix() << "hii";
    }
    */
}


