#ifndef _CLIENT_H
#define _CLIENT_H

#include "Temps.h"
#include "Commande.h"
#include <time.h>
#include <iostream>

using namespace  std;

class Client{

    private :

        Temps patience(unsigned int duree);
        int emplacement;
        int idClient; 
        Commande com;
        int prixTot;


    public :

        Client(); // on appelle le constructeur de temps pour creer un objet de la classe 

        ~Client();

        int paiement(); // renvoie le prixTot

};

#endif