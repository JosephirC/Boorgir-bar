#include "Temps.h"
#include "Commande.h"
#include "Client.h"
#include <time.h>
#include <iostream>

using namespace  std;


Client::Client(const unsigned int idC, Commande comm, const int prix){
    idClient=idC;
    com=comm;
    prixTot=prix;
}

Client::~Client(){

}

unsigned int Client::getIdC() const{
     return idClient;
 }

 unsigned int Client::getPrix() const{
     return prixTot;
 }

 Commande Client::getCom(){

     return com;
 }

