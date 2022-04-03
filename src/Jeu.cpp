#include "Jeu.h"
#include "Recette.h"
#include "Ingredient.h"
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

void Jeu::chargerCarte(vector<string> &tabC, const string &fileCarte){
    ifstream fileC(fileCarte.c_str());
    string nomR;
    if(fileC.is_open()){

        while(fileC >> nomR){
            tabC.push_back(nomR);
        }
        
        cout << "----------Voici la Carte----------" << endl << endl;

        for(unsigned int i = 0; i < tabC.size(); i++){
            cout << tabC[i] << endl;
        }

        fileC.close();
    }

    else 
        cout << "Failed to open file..." << endl;
}

void Jeu::recetteAleatoire(vector<string> &carte){
    srand(time(NULL));
    chargerCarte(carte, "./txt/Carte.txt");

    vector<string> commandeAl; // Tableau dynamique qui prend aleatoire des recettes de la carte

    unsigned int random1, random2, random3;
    unsigned int min1 = 0;
    unsigned int max1 = 5;
    unsigned int min2 = 6;
    unsigned int max2 = 9; // 9 car il y a une chance que la commande ne soit qu'une seule recette

    unsigned int frites = 6;
    unsigned int soda = 7;
    unsigned int jus = 8;
    unsigned int rien = 9;

    string recette1, recette2, recette3;

    for (unsigned int i = 0; i < 1; i++){
        random1 = rand()%(max1 - min1 + 1) + min1; // nombre aleatoire entre 0 et 5
        recette1 = carte[random1];
        cout << "recette1 : " << recette1 << endl;

        for(unsigned int j = 0; j < 1; j++){
            random2 = rand()%(max2 - min2 + 1) + min2; // nombre aleatoire entre 6 et 9
            recette2 = carte[random2];
            cout << "recette2 : " << recette2 << endl;
            
            for(unsigned int k = 0; k < 1; k++){
                random3 = rand()%(max2 - min2 + 1) + min2; // nombre aleatoire entre 6 et 9

                if(random3 == random2){
                    cout << "recette3 = NULL" << endl;
                    cout << "Pas de 3eme recette " << endl;
                    break;
                }

                else{
                    if(random3 == frites){
                        recette3 = carte[frites];
                        cout << "recette3 : " << recette3 << endl;
                    }
                    else{
                        if(random3 == soda && random3 != jus){
                            recette3 = carte[soda];
                            cout << "recette3 : " << recette3 << endl;
                        }
                        else{
                            if(random3 == jus && random3 != soda){
                                recette3 = carte[jus];
                                cout << "recette3 : " << recette3 << endl;
                            }
                            else{
                                recette3 = carte[rien];
                                cout << "recette3 : " << recette3 << endl;
                            }    
                        }
                    }
                }
            }
        }
        cout << "random1 = " << random1 << endl;
        cout << "random2 : " << random2 << endl;
        cout << "random3 : " << random3 << endl;

    }
    commandeAl.push_back(recette1);
    commandeAl.push_back(recette2);
    commandeAl.push_back(recette3);

    for(unsigned int i = 0; i < commandeAl.size(); i++){
        cout << endl << "Transfer reussi et la commande est : " << endl;
        for(unsigned int j = 0; j < 1; j++){
            cout  << "Recette" << i+1 << " = " << commandeAl[i] << endl << endl;
        }
    }
}