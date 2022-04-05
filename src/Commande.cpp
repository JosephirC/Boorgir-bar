#include "Jeu.h"
#include "Commande.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


Commande::Commande()
{
    nomC = " ";
    prixC = 0;
}

Commande::Commande(string nom, unsigned int prix){
    nomC = nom;
    prixC = prix;
}

Commande:: ~Commande(){   
    
}

void Commande::setNom(const string & nom){
    nomC = nom;
}

void Commande::setPrix(const unsigned int & prix){
    prixC = prix;
}

string Commande::getNom() const{
    return nomC;
}

unsigned int Commande::getPrix() const{
    return prixC;    
}

ostream &operator<< (ostream & flux, const Commande &c){
    flux << "Commande : " << c.getNom() << " | Prix : " << c.getPrix() << "$" << endl;
    return flux;
}

void Commande::chargerCarte(vector<Commande> &tabC, const string &fileCarte){
    ifstream fileC(fileCarte.c_str());
    string nom;
    int prix;
    if(fileC.is_open()){

        while(fileC >> nom >> prix){
            Commande c(nom, prix);
            tabC.push_back(c);
        }
        
        //cout << "----------Voici un client----------" << endl;

        for(unsigned int i = 0; i < tabC.size(); i++){
            //cout << tabC[i] << endl;
        }

        fileC.close();
    }

    else 
        cout << "Failed to open file..." << endl;
}

void Commande::commandeAleatoire(vector<Commande> &carte, vector<Commande> & commandeAl){  // commandeAl : Tableau dynamique qui prend aleatoire des recettes de la carte
    chargerCarte(carte, "./txt/Carte.txt");

    unsigned int random1, random2, random3;
    unsigned int min1 = 0;
    unsigned int max1 = 5;
    unsigned int min2 = 6;
    unsigned int max2 = 8; // 9 car il y a une chance que la commande ne soit qu'une seule recette

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

                if(random3 == random2){
                    //cout << "recette3 = NULL" << endl;
                    //cout << "Pas de 3eme recette " << endl;
                    nom3 = " ";
                    prix3 = 0;
                    Commande c3(nom3, prix3);
                    commandeAl.push_back(c3);
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
                            }   */ 
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




void Commande::calculePrix(vector<Commande>  & commandeAl, unsigned int & prix){
    vector<Commande> carte;
    commandeAleatoire(carte, commandeAl);
    prix = 0;

    for(unsigned int i = 0; i<commandeAl.size(); i++){
        //cout << commandeAl[i].getNom() << " " << commandeAl[i].getPrix() << endl;
        prix = prix + commandeAl[i].getPrix();
    }
    //cout << "Le prix de la commande est : " << prix << endl;
}
