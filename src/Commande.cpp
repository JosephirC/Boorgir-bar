#include "Jeu.h"
#include "Commande.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


Commande::Commande()
{
    nomC = "";
    prixC = 0;
}

Commande::Commande(string nom, unsigned int prix){
    nomC = nom;
    prixC = prix;
}

Commande:: ~Commande(){   

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
        
        cout << "----------Voici la Carte----------" << endl << endl;

        for(unsigned int i = 0; i < tabC.size(); i++){
            cout << tabC[i] << endl;
        }

        fileC.close();
    }

    else 
        cout << "Failed to open file..." << endl;
}

void Commande::commandeAleatoire(vector<Commande> &carte, vector<string> & commandeAl){  // commandeAl : Tableau dynamique qui prend aleatoire des recettes de la carte
    srand(time(NULL));
    chargerCarte(carte, "./txt/Carte.txt");

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
        recette1 = carte[random1].getNom();
        cout << "recette1 : " << recette1 << endl;

        for(unsigned int j = 0; j < 1; j++){
            random2 = rand()%(max2 - min2 + 1) + min2; // nombre aleatoire entre 6 et 9
            recette2 = carte[random2].getNom();;
            cout << "recette2 : " << recette2 << endl;
            
            for(unsigned int k = 0; k < 1; k++){
                random3 = rand()%(max2 - min2 + 1) + min2; // nombre aleatoire entre 6 et 9

                if(random3 == random2){
                    cout << "recette3 = NULL" << endl;
                    cout << "Pas de 3eme recette " << endl;
                }

                else{
                    if(random3 == frites){
                        recette3 = carte[frites].getNom();
                        cout << "recette3 : " << recette3 << endl;
                    }
                    else{
                        if(random3 == soda && random2 != jus){
                            recette3 = carte[soda].getNom();
                            cout << "recette3 : " << recette3 << endl;
                        }
                        else{
                            if(random3 == jus && random2 != soda){
                                recette3 = carte[jus].getNom();
                                cout << "recette3 : " << recette3 << endl;
                            }
                            else{
                                recette3 = carte[rien].getNom();
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

unsigned int Commande::calculePrix(vector<string> commandeAl){
    vector<Commande> carte;
    commandeAleatoire(carte, commandeAl);

    cout << "test" << endl;

    for(unsigned int i = 0; i<carte.size(); i++){
        cout << carte[i].getNom() << " " << carte[i].getPrix() << endl;
    }

    cout << "test 2" << endl;


    return 0;
}
