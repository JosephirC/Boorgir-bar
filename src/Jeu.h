#ifndef _JEU_H
#define _JEU_H

#include "Ingredient.h"
#include "Recette.h"
#include "Client.h"
#include "Temps.h"
#include "Objectif.h"
#include <vector>
#include <iostream>

using namespace  std;

/*enum class TypeNiveau {
    Facile;
    Difficile;
    Crazy;
}*/

class Jeu{

    private :

        
        //Temps tempsJ(int periode);
        Objectif obj; 
        int additionArgent;  // additionArgent = tabC[i].paiement;
        int ingSelectionne; // prend la valeur de l'emplacement de l'ingredient selectionner/// REMARQUE IL FAUT METTRE L EMPLACEMENT ICI 
        bool estSelectionne;
        //faire un tab statique de taille 11, chaque case contient les coordonnees x y pour chaque ingredient  dans SDL


    public :
        vector<Client> tabClient;   // Contient les Clients cree qui arrivent au restau
        vector<Commande> carte;     // Contient le chargement de la carte du restau
        vector<Ingredient> tabIng;  //[50]
        vector<Recette> tabRec;     //Contient le tableau de recette entier avec toutes les etapes possibles
        //vector<string> tabPreps;     //Contient les burger en cours de preparation
        string tabPrep[4];

        Jeu();

        Jeu(int typeJeu, int niveau); // il faut lire un fichier .txt qui contient les niveau avec le nbr de client / temps en parametres dans le constructur avec un ifstream

        ~Jeu();

        Objectif & getObj();

        //void chargerIngredient(Ingredient *tabIng, const string& nom_ingredient);
        void chargerIngredient(vector<Ingredient> & tabI, const string& fileIngredient);
        void chargerRecette(vector<Recette> & tabR, const string& fileRecette);
        void chargerCarte(vector<Commande> & tabC, const string &fileCarte);

        //const vector<Commande>& getCarte() const;
        //void setCarte(vector<Commande> carte);
        //const vector<Recette>& getvector() const {return tabRec;}
        //void setvector(vector<Recette> vec){tabRec = vec;}

        string getNomCarte() const ; //Accesseur : recupere le nom de la recette de la carte

        void commandeAleatoire(vector<string> carte, vector<string> & commandeAl);

        Client & getClient(const unsigned int &IdC) const;
        void setClient(const unsigned int &IdC, const Client &c);

        void creationClient(const unsigned int &I, vector<Client> &tabC,vector<Commande> &carte );

        string PreparerCommande( const string & ing, int i);

        string creationRecette(const string & recette,vector<Recette> &recVec);
        bool compareRecette(vector<Recette> & tabR, vector<Client> & tabC, const string & r, unsigned int & IdCl);
        void effaceRecette(vector<Client> & Cl, unsigned int & IdCl, string & rec);


};

#endif
