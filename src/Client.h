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
        int prixTot;
       

    public :
        
        vector<Commande> com;

        /** < @brief un construscteur de Client */ 
        Client();
        /** < @brief un constructeur de Client */ 
        Client(const unsigned int idC, vector<Commande> & comm, unsigned int prix); // on appelle le constructeur de temps pour creer un objet de la classe 
        /** < @brief le destructeur de Client */ 
        ~Client();

        /** < @brief  */
        int paiement(); // renvoie le prixTot

        /** < @brief fonction qui retourne l'identifiant du Client */ 
        unsigned int getIdC() const;
        /** < @brief fonction qui retourne le prix total de la commande du client */ 
        unsigned int getPrix() const;

        //Commande getCom();
};

#endif