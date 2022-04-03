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
            //cout << nomIng << " " << prix << " " << pos << " " << tempsCuisson << endl;
        }

        for(unsigned int i = 0; i < ingVec.size(); i++){
            //cout << ingVec[i] << endl;
        }
        fileIng.close();
    }

    else 
        cout << "Failed to open file..." << endl;
}


void Jeu::chargerRecette(const string &filenameRec){
    vector<Recette> recVec;
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
            for(unsigned int i = 0; i < recVec.size(); i++){
                cout << recVec[i] << endl;
            }
            fileRec.close();
    }else{
        cout << "Failed to open file..." << endl;
    }


    /*
   // vector<string> nomIngRec;  //car on va mettre le nom seulement pas Ingredients
    if(fileRec.is_open()){

        //Pour ignorer la premiere ligne
		string buff;
		getline(fileIng, buff);

        string line;
        while(!fileRec.eof()){
            getline(fileRec, line);
            if (fileRec.good()){
                iss.clear();
                iss.str(line);
                while (iss.good()){
                    iss>>nom;

                    cout << nom <<endl;

                }

            }

        }
    }else{
        cout << "Failed to open file..." << endl;
    }
    */

    /*
    if(fileRec.is_open()){
        while(fileRec >> nom >> nbr){
            cout << "hi?";
                vector<string> nomIngRec;  //car on va mettre le nom seulement pas Ingredients
                for (int i=0;i<nbr;i++){
                    while(fileRec >> nom){
                    nomIngRec.push_back(nom);
                    }
                }
                while(fileRec >> prix){
                    Recette rec(nom,nbr,nomIngRec,prix);
                    recVec.push_back(rec);
                    cout << nom << " " << nbr <<endl;
                }

            }
        fileRec.close();
    }
    else{
        cout << "Failed to open file..." << endl;
    }
    */
}
