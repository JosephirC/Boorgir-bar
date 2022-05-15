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

/*
const vector<Commande>& Jeu::getCarte() const {
    return carte;
}

void Jeu::setCarte(vector<Commande> cart){
    carte = cart;
}
*/

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

/** < @brief charge les recettes*/
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


/** < @brief charge la carte */
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


/** < @brief creation du client et de sa comande */
void Jeu::creationClient(const unsigned int &I, vector<Client> & tabC,vector<Commande> & carte){
    unsigned int i;
    for(i=0;i<I;i++){
        Client cli(i+1, carte);
        tabC.push_back(cli);
    }
}


/** < @brief prepare la commande  */
string Jeu::PreparerCommande( const string & ing , int i ){
    for (unsigned int j=0;j<tabRec.size();j++){
        if( ing=="Soda" || ing=="Jus" || ing=="Frites") break;
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
    bool trouve = false;
        for(unsigned int j = 0; j < tabClient[IdCl].getCom().size() ; j++){

            cout<<tabClient[IdCl].getCom().size()<<" size et nom "<<tabClient[IdCl].getCom()[j].getNom()<<endl;
            if(tabClient[IdCl].getCom()[j].getNom() == tabPrep[IdRec]){

                cout<<endl<<tabClient[IdCl].getCom()[j].getNom();
                tabClient[IdCl].getCom().erase( tabClient[IdCl].getCom().begin()+2);  
                
                cout<<endl<<" AFTER: "<<tabClient[IdCl].getCom()[j].getNom()<< " et taille "<<tabClient[IdCl].getCom().size();
                
                trouve = true;
                tabPrep[IdRec]="Undefined";
                break;
            }
            if(trouve == true){
                break;
            }
    }
}

/*
void Jeu::erase(){
    for (unsigned int i=0 ; i<tabClient.size)
}
*/
/** < @brief permet d'effacer un extra */
void Jeu::effaceExtras(vector<Client> & Cl, unsigned int & IdCl, unsigned int & IdExtras){
    bool trouve = false;
        for(unsigned int j = 0; j < Cl[IdCl].getCom().size(); j++){

            cout<<Cl[IdCl].getCom().size()<<endl;
            if(Cl[IdCl].getCom()[j].getNom() == tabPrep[IdExtras]){

                cout<<Cl[IdCl].getCom()[j].getNom();

                //tabClient[IdCl].setCom( Cl[IdCl].getCom().erase(Cl[IdCl].getCom().begin() + j));
                //tabClient[IdCl].getCom().erase(Cl[IdCl].getCom().begin() + j);
                //tabClient[IdCl].setCom(tabClient[IdCl].getCom());

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

/** < @brief permet d'effacer un client */
bool Jeu::effacerClient(vector<Client> & Cl){
    //bool efface = false;
    if(Cl.empty() == true ){
        creationClient(4,tabClient ,carte);
        return true;
    }
    return false;
}
