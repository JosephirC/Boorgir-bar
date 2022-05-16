#ifndef _CLIENT_H
#define _CLIENT_H

#include "Temps.h"
#include "Commande.h"
#include <time.h>
#include <iostream>

using namespace  std;

class Client{

    private :

        //Temps patience(unsigned int duree);
        //int emplacement;
        /** < @param idClient Identifiant du client */
        unsigned int idClient; 
        /** < @param prixTot Prix total de la commande du client */
        unsigned int prixTot ;
        
        /** < @param com Vecteur commande */
        vector<Commande> com; 
               
       

    public :
        
        

        /** < @brief Construscteur de Client */ 
        Client();
        /** < @brief Constructeur de Client 
         * @param idC identifiant du client
         * @param carte contient toutes les recettes possibles
        */ 
        Client(const unsigned int idC, vector<Commande> & carte); // on appelle le constructeur de temps pour creer un objet de la classe 
        /** < @brief Destructeur de Client */ 
        ~Client();

        /** < @brief Accesseur : recupere l'identifiant du Client */ 
        unsigned int getIdC() const;
        /** < @brief Accesseur : recupere le prix total de la commande du client */ 
        unsigned int getPrix() const;
        /** < @brief Mutateur : modifie le prix total de la commande di client 
         * @param prix prix de la commande
        */
        void setPrix(const unsigned int & prix);

        /** < @brief Accesseur : recupere la commande */
        vector<Commande> getCom() const;
        /** < @brief Mutateur : modifie la commande 
         * @param c commande
        */
        void setCom(vector<Commande> c);

        /** < @brief Choisi des recettes aleatoire du menu pour le donner au client
         * @param carte contient toutes les recettes possibles
         */
        void commandeAleatoire(const vector<Commande> & carte); // remplie le tableau de commande avec des recette entre 1 et 3

        /** < @brief Procedure qui calcule le prix que le client doit payer */
        void calculePrix(); 

        /** < @brief Procedure: qui efface un element d'indice j du vecteur com
         *  @param j indice de a commande que l'on veut effacer
        */
        void erase(int j);

};

#endif