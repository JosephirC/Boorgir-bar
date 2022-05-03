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

        /** < @param Contient les burger en cours de preparation prend la valeur de l'emplacement de l'ingredient selectionner*/ 
        int ingSelectionne; /// REMARQUE IL FAUT METTRE L EMPLACEMENT ICI 

        bool estSelectionne;
        //faire un tab statique de taille 11, chaque case contient les coordonnees x y pour chaque ingredient  dans SDL


    public :

        /** < @brief Contient les Clients cree qui arrivent au restau */
        vector<Client> tabClient; 
        /** < @brief Contient le chargement de la carte du restau */  
        vector<Commande> carte; 

        vector<Ingredient> tabIng;  //[50]
        /** < @brief Contient le tableau de recette entier avec toutes les etapes possibles */
        vector<Recette> tabRec;     
        /** < @brief Contient les burger en cours de preparation */
        //vector<string> tabPreps; 

        string tabPrep[4];

        /** < @brief  */
        Jeu();
        /** < @brief  */
        Jeu(int typeJeu, int niveau); /** < @brief il faut lire un fichier .txt qui contient les niveau avec le nbr de client / temps en parametres dans le constructur avec un ifstream */
        /** < @brief destructeur Jeu */
        ~Jeu();
        /** < @brief retourne les objetid$f du jeu */
        Objectif & getObj();

        //void chargerIngredient(Ingredient *tabIng, const string& nom_ingredient);

        /** < @brief charge tous les ingredients*/
        void chargerIngredient(vector<Ingredient> & tabI, const string& fileIngredient);
        /** < @brief charge les recettes*/
        void chargerRecette(vector<Recette> & tabR, const string& fileRecette);
        /** < @brief charge la carte*/
        void chargerCarte(vector<Commande> & tabC, const string &fileCarte);

        //const vector<Commande>& getCarte() const;
        //void setCarte(vector<Commande> carte);
        //const vector<Recette>& getvector() const {return tabRec;}
        //void setvector(vector<Recette> vec){tabRec = vec;}

        /** < @brief  */
        string getNomCarte() const ; //Accesseur : recupere le nom de la recette de la carte
        /** < @brief  */
        void commandeAleatoire(vector<string> carte, vector<string> & commandeAl);


        /** < @brief  */
        Client & getClient(const unsigned int &IdC) const;
        /** < @brief  */
        void setClient(const unsigned int &IdC, const Client &c);

        /** < @brief creation du client et de sa comande */
        void creationClient(const unsigned int &I, vector<Client> &tabC,vector<Commande> &carte );
        /** < @brief prepare la commande  */
        string PreparerCommande( const string & ing, int i);

        /** < @brief ajouter une nouvelle recete au menu */
        string creationRecette(const string & recette,vector<Recette> &recVec);
        /** < @brief fonction permettant de comparer les recettes */
        bool compareRecette(vector<Recette> & tabR, vector<Client> & tabC, const string & r, unsigned int & IdCl);
        /** < @brief permet d'effacer une recette */
        void effaceRecette(vector<Client> & Cl, unsigned int & IdCl, string & rec); 
        
        bool effacerClient(vector<Client> & Cl);


};

#endif
