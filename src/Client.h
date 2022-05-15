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
        /** < @brief identifiant du client */
        unsigned int idClient; 
        /** < @brief prix total de la commande du client */
        unsigned int prixTot ;

        vector<Commande> com;        
       

    public :
        
        

        /** < @brief un construscteur de Client */ 
        Client();
        /** < @brief un constructeur de Client */ 
        Client(const unsigned int idC, vector<Commande> & carte); // on appelle le constructeur de temps pour creer un objet de la classe 
        /** < @brief le destructeur de Client */ 
        ~Client();

        /** < @brief  */
        int paiement(); // renvoie le prixTot

        /** < @brief fonction qui retourne l'identifiant du Client */ 
        unsigned int getIdC() const;
        /** < @brief fonction qui retourne le prix total de la commande du client */ 
        unsigned int getPrix() const;

        vector<Commande> getCom() const;
        void setCom(vector<Commande> c);

        //Commande getCom();
        /** < @brief, choisi des recettes aleatoire du menu pour le donner au client */
        void commandeAleatoire(const vector<Commande> & carte, vector<Commande> & commendeAl); // remplie le tableau de commande avec des recette entre 1 et 3

        /** < @brief fonction qui calcule le prix que le client doit payer */
        void calculePrix(vector<Commande> &commandeAl, unsigned int & prix); // retourne le prix de la commande

};

#endif