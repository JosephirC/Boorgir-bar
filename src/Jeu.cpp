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

vector<Client> & Jeu::getTabClient(){
     return tabClient;
 }

vector<Commande> & Jeu::getCarte(){
     return carte;
}
vector<Ingredient> & Jeu::getTabIng(){
     return tabIng;
}
vector<Recette> & Jeu::getTabRec(){
     return tabRec;
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
        
        /*cout << "----------Voici tous les Ingredients----------" << endl << endl;

        for(unsigned int i = 0; i < ingVec.size(); i++){
            cout << ingVec[i] << endl;
        }*/

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
    unsigned int i;
    for(i=0;i<I;i++){
        Client cli(i+1, carte);
        tabC.push_back(cli);
    }
}

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
}

void Jeu::effaceRecette(vector<Client> & Cl, unsigned int & IdCl, unsigned int & IdRec){
    bool trouve = false;
        for(unsigned int j = 0; j < Cl[IdCl].getCom().size(); j++){

            cout<<Cl[IdCl].getCom().size()<<endl;
            if(Cl[IdCl].getCom()[j].getNom() == tabPrep[IdRec] ){

                cout<<Cl[IdCl].getCom()[j].getNom();
                Cl[IdCl].getCom().erase(Cl[IdCl].getCom().begin() + j);    
                trouve = true;
                tabPrep[IdRec]="Undefined";
                break;
            }
            if(trouve == true){
                break;
            }
    }
}

void Jeu::effaceExtras(vector<Client> & Cl, unsigned int & IdCl, unsigned int & IdExtras){
    bool trouve = false;
        for(unsigned int j = 0; j < Cl[IdCl].getCom().size(); j++){

            cout<<Cl[IdCl].getCom().size()<<endl;
            if(Cl[IdCl].getCom()[j].getNom() == tabPrep[IdExtras] ){

                cout<<Cl[IdCl].getCom()[j].getNom();
                Cl[IdCl].getCom().erase(Cl[IdCl].getCom().begin() + j);    
                trouve = true;
                tabPrep[IdExtras]="Undefined";
                break;
            }
            if(trouve == true){
                break;
            }
    }
}


bool Jeu::effacerClient(vector<Client> & Cl){
    //bool efface = false;
    if(Cl.empty() == true ){
        creationClient(4,tabClient ,carte);
        return true;
    }
    return false;
}
