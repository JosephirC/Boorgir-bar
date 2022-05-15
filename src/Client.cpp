#include "Temps.h"
#include "Commande.h"
#include "Client.h"
#include <time.h>
#include <iostream>

using namespace  std;


/** < @brief Constructeur de Client */ 
Client::Client(const unsigned int idC,vector<Commande> & carte){
    prixTot=0;
    idClient=idC;
    commandeAleatoire(carte,com);
    calculePrix(com, prixTot);
}



/** < @brief Destructeur de Client */ 
Client::~Client(){
 
}

/** < @brief fonction qui retourne l'identifiant du Client */ 
unsigned int Client::getIdC() const{
     return idClient;
 }

/** < @brief fonction qui retourne le prix total de la commande du client */ 
 unsigned int Client::getPrix() const{
     return prixTot;
 }

vector<Commande> Client::getCom()const {
     return com;
 }

void Client::setCom(vector<Commande> c){
    com = c;
}

/** < @brief, choisi des recettes aleatoire du menu pour le donner au client */
void Client::commandeAleatoire(const vector<Commande> &carte, vector<Commande> & commandeAl){  // commandeAl : Tableau dynamique qui prend aleatoire des recettes de la carte
    //chargerCarte(carte, "./txt/Carte.txt");

    unsigned int random1, random2, random3;
    unsigned int min1 = 0;
    unsigned int max1 = 5;
    unsigned int min2 = 6;
    unsigned int max2 = 8; //  

    unsigned int frites = 6;
    unsigned int soda = 7;
    unsigned int jus = 8;
    //unsigned int rien = ;

    string recette1, recette2, recette3, nom1, nom2, nom3;
    unsigned int prix1, prix2, prix3;

        random1 = rand()%(max1 - min1 + 1) + min1; // nombre aleatoire entre 0 et 5
        nom1 = carte[random1].getNom();
        prix1 = carte[random1].getPrix();
        Commande c1(nom1, prix1);
        commandeAl.push_back(c1);
        //cout << "recette1 : " << commandeAl[0] << endl;

            random2 = rand()%(max2 - min2 + 1) + min2; // nombre aleatoire entre 6 et 9
            nom2 = carte[random2].getNom();
            prix2 = carte[random2].getPrix();
            Commande c2(nom2, prix2);
            commandeAl.push_back(c2);
            //cout << "recette2 : " << commandeAl[1] << endl;
            
                random3 = rand()%(max2 - min2 + 1) + min2; // nombre aleatoire entre 6 et 9

                if(random3 == random2){ // Il ne fait rien !
                    //cout << "recette3 = NULL" << endl;
                    //cout << "Pas de 3eme recette " << endl;           
                }

                else{
                    if(random3 == frites){
                        nom3 = carte[frites].getNom();
                        prix3 = carte[frites].getPrix();
                        Commande c3(nom3, prix3);
                        commandeAl.push_back(c3);
                        //cout << "recette3 : " << commandeAl[2] << endl;
                    }
                    else{
                        if(random3 == soda && random2 != jus){
                            nom3 = carte[soda].getNom();
                            prix3 = carte[soda].getPrix();
                            Commande c3(nom3, prix3);
                            commandeAl.push_back(c3);
                            //cout << "recette3 : " << commandeAl[2] << endl;
                        }
                        else{
                            if(random3 == jus && random2 != soda){
                                nom3 = carte[jus].getNom();
                                prix3 = carte[jus].getPrix();
                                Commande c3(nom3, prix3);
                                commandeAl.push_back(c3);
                                //cout << "recette3 : " << commandeAl[2] << endl;
                            }
                            /*else{
                                nom3 = carte[rien].getNom();
                                prix3 = carte[rien].getPrix();
                                Commande c3(nom3, prix3);
                                commandeAl.push_back(c3);
                                cout << "recette3 : " << commandeAl[2] << endl;
                            }  */ 
                        }
                    }
                }
        //cout << "random1 = " << random1 << endl;
        //cout << "random2 : " << random2 << endl;
        //cout << "random3 : " << random3 << endl;

    for(unsigned int i = 0; i < commandeAl.size(); i++){
        //cout << endl << "Transfer reussi et la commande est : " << endl;
        for(unsigned int j = 0; j < 1; j++){
            //cout  << "Recette" << i+1 << " = " << commandeAl[i] << endl << endl;
        }
    }
}

/** < @brief fonction qui calcule le prix que le client doit payer */
void Client::calculePrix(vector<Commande>  & commandeAl, unsigned int & prix){
    prix = 0;
    for(unsigned int i = 0; i<commandeAl.size(); i++){
        prix = prix + commandeAl[i].getPrix();
    }
    //cout << "Le prix de la commande est : " << prix << endl;
}
