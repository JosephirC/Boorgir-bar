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

        /** < @param obj Objectif de la partie */
        Objectif obj; 
        /** < @param additionArgent Additionne l'argent gagne */
        unsigned int additionArgent;  

        /** < @param tabClient Contient les Clients cree qui arrivent au restau */
        vector<Client> tabClient; 
        /** < @param carte Contient le chargement de la carte du restau */  
        vector<Commande> carte; 
        /** < @param tabIng Contient le tableau d'ingredients*/
        vector<Ingredient> tabIng;  //[50]
        /** < @param tabRec Contient le tableau de recette entier avec toutes les etapes possibles */
        vector<Recette> tabRec;     

    public :

        /** < @param tabPrep Tableau de preparation */
        string tabPrep[4];

        /** < @brief Constructeur de la classe Jeu */
        Jeu();
        
        /** < @brief Destructeur de la classe Jeu */
        ~Jeu();

        /** < @brief Accesseur : recupere les objectifs du jeu */
        Objectif & getObj();

        /** < @brief Charge tous les ingredients
         * < @param fileIngredient chemin vers le fichier Ingredient
        */
        void chargerIngredient(const string& fileIngredient);
        /** < @brief Charge les recettes
         * < @param fileRecette chemin vers le fichier Recette
        */
        void chargerRecette(const string& fileRecette);
        /** < @brief Charge la carte 
         * < @param fileCarte chemin vers le fichier Carte
        */
        void chargerCarte(const string &fileCarte);

        /** < @brief Accesseur : recupere le tableau des clients */
        vector<Client> & getTabClient();
        /** < @brief Accesseur : recupere la carte */
        vector<Commande> & getCarte();
        /** < @brief Accesseur : recupere le tableau des ingredients */
        vector<Ingredient> & getTabIng();
        /** < @brief Accesseur : recupere le tableau des recettes */
        vector<Recette> & getTabRec();

        /** < @brief Accesseur : recupere la somme d'argent */
        unsigned int & getAdditionArgent();
        /** < @brief Mutateur : modifie la somme d'argent 
         * < @param i somme d'argent
        */
        void setAdditionArgent(unsigned int & i);

        /** < @brief Accesseur : recupere le nom de la recette de la carte */
        string getNomCarte() const ;


        /** < @brief creation du client et de sa comande 
         * < @param I taille du vecteur
        */
        void creationClient(const unsigned int &I);
        /** < @brief Prepare la commande 
         * < @param ing ingredient 
         * < @param i indice du client dont on recupere l'argent
         */
        string PreparerCommande( const string & ing, int i);

 
        /** < @brief Permet d'effacer une recette 
         * < @param IdCl identifiant du client
         * < @param IdRec identifiant de la recette
        */
        void effaceRecette(unsigned int & IdCl, unsigned int & IdRec);
        /** < @brief Permet d'effacer un extra 
         * < @param IdCl identifiant du client
         * < @param ing ingredient
        */
        void effaceExtras(unsigned int & IdCl, const string & ing);
        /** < @brief Calcule combien d'argent on a gagne au cours de la partie 
         * < @param i indice du client dont on recupere l'argent
        */
        void money(unsigned int & );
        /** < @brief Permet d'effacer un client */
        bool nouveauClient();
        /** < @brief Nous dit si on a atteint la somme d'argent demande de la partie */
        bool argentAtteint();
        /** < @brief Fait le test de regression */ 
        void testDeRegression();

};

#endif
