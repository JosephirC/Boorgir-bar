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

/** < @brief constructeur de la classe Jeu */
Jeu::Jeu(){

}

/** < @brief constructeur de la classe Jeu */
Jeu::Jeu(int typeJeu, int niveau){

}

/** < @brief destructeur de la classe Jeu */
Jeu::~Jeu(){
    
}

/** < @brief accesseur : recupere les objectifs du jeu */
Objectif & Jeu::getObj(){
     return obj;
 }

/** < @brief accesseur : recupere le tableau des clients */
vector<Client> & Jeu::getTabClient(){
     return tabClient;
 }

/** < @brief accesseur : recupere la carte */
vector<Commande> & Jeu::getCarte(){
     return carte;
}

/** < @brief accesseur : recupere le tableau des ingredients */
vector<Ingredient> & Jeu::getTabIng(){
     return tabIng;
}

/** < @brief accesseur : recupere le tableau des recettes */
vector<Recette> & Jeu::getTabRec(){
     return tabRec;
}

int & Jeu::getAdditionArgent(){
    return additionArgent;
}

void Jeu::setAdditionArgent(unsigned int & i){
    additionArgent=i;
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

/** < @brief charge tous les ingredients*/
void Jeu::chargerIngredient(const string &filenameIng){
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
            tabIng.push_back(ing);
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

/** < @brief charge les recettes*/
void Jeu::chargerRecette(const string &filenameRec){
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
                    tabRec.push_back(Rec);
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


/** < @brief charge la carte */
void Jeu::chargerCarte(const string &fileCarte){
    ifstream fileC(fileCarte.c_str());
    string nom;
    int prix;
    if(fileC.is_open()){
        while(fileC >> nom >> prix){
            Commande c(nom, prix);
            carte.push_back(c);
        }
        fileC.close();
    }
    else 
        cout << "Failed to open file..." << endl;
}


/** < @brief creation du client et de sa comande */
void Jeu::creationClient(const unsigned int &I){
    unsigned int i;
    for(i=0;i<I;i++){
        Client cli(i+1, carte);
        tabClient.push_back(cli);
    }
}


/** < @brief prepare la commande  */
string Jeu::PreparerCommande( const string & ing , int i ){
    for (unsigned int j=0;j<tabRec.size();j++){
        if( ing=="Soda" || ing=="Jus" || ing=="Frites") return tabPrep[i] ;
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

/** < @brief permet d'effacer une recette */
void Jeu::effaceRecette(unsigned int & IdCl, unsigned int & IdRec){
        for(unsigned int j = 0; j < tabClient[IdCl].getCom().size() ; j++){
            if(tabClient[IdCl].getCom()[j].getNom() == tabPrep[IdRec]){
                tabClient[IdCl].erase(j);
                tabPrep[IdRec]="Undefined";
                break;
            }
    }
}


/** < @brief permet d'effacer un extra */
void Jeu::effaceExtras(unsigned int & IdCl, const string & ing){
    cout<<ing<<endl;
    for(unsigned int j = 0; j < tabClient[IdCl].getCom().size() ; j++){
        if(tabClient[IdCl].getCom()[j].getNom() == ing ){
            tabClient[IdCl].erase(j);
            break;
        }
    }  
}

void Jeu::money(unsigned int & i){ 
    if(tabClient[i].getCom().size() == 0){
        additionArgent+=tabClient[i].getPrix();
        tabClient[i].setPrix(0);
    } 
}

/** < @brief permet d'effacer un client */
bool Jeu::effacerClient(){
    //bool efface = false;
    if(tabClient.empty() == true ){
        creationClient(4);
        return true;
    }
    return false;
}
