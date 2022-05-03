#include "Temps.h"
#include "Commande.h"
#include "Client.h"
#include <time.h>
#include <iostream>

using namespace  std;


/** < @brief Constructeur de Client */ 
Client::Client(const unsigned int idC, vector<Commande> & comm, unsigned int prix){
    idClient=idC;
    com=comm;
    prixTot=prix;
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

 /*Commande Client::getCom(){

     return com;
 }*/

