#include "Jeu.h"
#include "Recette.h"
#include "Ingredient.h"
#include "Commande.h"
#include "Client.h"
#include "Temps.h"
#include "Objectif.h"
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

Objectif & Jeu::getObj(){
     return obj;
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
                    for (int i=0 ;i<nbr;i++){
                        iss >>nomI;
                        nomIngRec.push_back(nomI);
                    }
                    iss >> prix;
                    Recette Rec(nom,nbr,nomIngRec,prix);
                    recVec.push_back(Rec);
                    nomIngRec.clear();
                }
            }
        }
        fileRec.close();
    }
    else
        cout << "Failed to open file..." << endl;
    
}


ostream &operator<< (ostream & flux, const Commande &c){
    flux << "Commande : " << c.getNom() << " | Prix : " << c.getPrix() << "$" << endl;
    return flux;
}

void Jeu::chargerCarte(vector<Commande> &tabC, const string &fileCarte){
    ifstream fileC(fileCarte.c_str());
    string nom;
    int prix;
    if(fileC.is_open()){
        while(fileC >> nom >> prix){
            Commande c(nom, prix);
            tabC.push_back(c);
        }
        fileC.close();
    }
    else 
        cout << "Failed to open file..." << endl;
}


void Jeu::creationClient(const unsigned int &I, vector<Client> & tabC,vector<Commande> & carte){
    Commande com1;
    vector<Commande> comAl;
    unsigned int i, prix;
    for(i=0;i<I;i++){
        com1.commandeAleatoire(carte, comAl);
        com1.calculePrix(comAl, prix);
        Client cli(i+1, comAl, prix);
        tabC.push_back(cli);
        comAl.clear();
    }
    /*for(unsigned int i = 0; i < tabC.size(); i++){
        for(unsigned int j =0; j < tabC[i].com.size(); j++){
            cout << "Client : " << i <<" Nom : " << tabC[i].com[j].getNom() << " |Prix : " << tabC[i].com[j].getPrix() << endl; 
        }
    }*/
}

// PreparerCommande : 
string Jeu::PreparerCommande( const string & ing , int i ){
    for (unsigned int j=0;j<tabRec.size();j++){
        if( ing=="Soda" || ing=="Jus" || ing=="Frites") return ing;
        if( ing==tabRec[j].getTab()[0] && tabRec[j].getTab()[1]=="Undefined"){
            tabPrep[i]=tabRec[j].getNom();
            return ing;
        }
        if( ing==tabRec[j].getTab()[1] && tabPrep[i]==tabRec[j].getTab()[0]){
            tabPrep[i]=tabRec[j].getNom();
            return tabPrep[i];
        }
    }
    return tabPrep[i];
    /*int i=0;
    if( ing=="Soda" || ing=="Jus") return ing;
    if( ing=="PainB") {
        while(i < 4){
            if( tabPrep[i].empty() ){
                tabPrep[i] = ing;
                return ing;
            }
            else i++;
        }
    }
    if( ing=="Steak"){
        while(i < 4){
            if( tabPrep[i] == "PainB"){
                tabPrep[i] = "B_Steak";
                return ing;
            }
            else i++;
        }
    }
    if( ing=="Tomate"){
        while(i < 4){
            if( tabPrep[i] == "B_Steak"){
                tabPrep[i] == "B_Steak";

            }
        }
    }
    */

}



/*
string Jeu::creationRecette(const string & recette, vector<Recette> &vecRec){
    //bool trouve = false;
    for(unsigned int i = 0; i < vecRec.size(); i++){
        cout << endl << endl << "RECETTE PASSE EN PARAM : " << recette << endl;
        cout << "rec ==== " << vecRec[i].getNom() << endl;
        
        if(recette == vecRec[i].getNom()){
            //cout << trouve << endl;
            //trouve = true; 
            //cout << trouve << endl;
            cout << "FOUND2"<< endl;
            return recette;
        }
     
    }
    return "";
}


bool Jeu::compareRecette(vector<Recette> &tabR, vector<Client> & tabC, const string & r, unsigned int & IdCl){
    bool egale = false;
    //vector<Client> tabC; // pour le client
    //creationClient(I, tabC);
    string rec = creationRecette(r,tabRec);
    for(unsigned int i = 0; i < tabC.size(); i++){
        for(unsigned int j = 0; j < tabC[i].com.size(); j++){
            //cout << "Client : " << i <<"Nom : " << tabC[i].com[j].getNom() << endl;
            //cout << "i = " << i << endl;
            //cout << "lol" << endl;
            cout << endl;
            //cout << "recette " << rec << endl;
            //cout << "nom" << tabC[i].com[j].getNom() << endl;

            if(rec == tabC[i].com[j].getNom()){
                cout << "test" << endl;
                egale = true;
                cout << "FOUND" << endl;
                IdCl = i;
                tabR.clear();
                return egale;
            }
        }
    }
        tabR.clear();
        return egale;
}
*/
void Jeu::effaceRecette(vector<Client> & Cl, unsigned int & IdCl, string & rec){
    bool trouve = false;
    for(unsigned int i = 0; i < Cl.size(); i++){
        for(unsigned int j =0; j < Cl[i].com.size(); j++){

            if(Cl[i].com[j].getNom() == rec){
                Cl[i].com.erase(Cl[i].com.begin() + j);    
                trouve = true;
                for(unsigned int i=0; i<4;i++){
                    if(tabPrep[i]==rec){
                        //tabPrep[i]=NULL;
                    }

                } 
                break;
            }
        }
        if(trouve == true){
                break;
            }

    }
    
  /*  for(unsigned int i = 0; i < Cl.size(); i++){
        for(unsigned int j =0; j < Cl[i].com.size(); j++){
    cout << " NOUVEAU Client : " << i <<" Nom : " << Cl[i].com[j].getNom() << endl; 
        }
    }
    cout << "Done " << endl; */
}
