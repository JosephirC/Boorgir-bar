#include "Temps.h"
#include "Commande.h"
#include "Client.h"
#include <time.h>
#include <iostream>

using namespace  std;


/** < @brief Constructeur de Client 
 * @param idC identifiant du client
 * @param carte contient toutes les recettes possibles
*/ 
Client::Client(const unsigned int idC,vector<Commande> & carte){
    prixTot=0;
    idClient=idC;
    commandeAleatoire(carte);
    calculePrix();
}



/** < @brief Destructeur de Client */ 
Client::~Client(){
 
}

/** < @brief Accesseur : recupere l'identifiant du Client */ 
unsigned int Client::getIdC() const{
     return idClient;
 }

/** < @brief Accesseur : recupere le prix total de la commande du client */ 
 unsigned int Client::getPrix() const{
     return prixTot;
 }

/** < @brief Mutateur : modifie le prix total de la commande du client 
 * @param prix prix de la commande
*/
 void Client::setPrix(const unsigned int & prix){
     prixTot=prix;
 }

/** < @brief Accesseur : recupere la commande */
vector<Commande> Client::getCom()const {
     return com;
 }

/** < @brief Mutateur : modifie la commande 
 * @param c commande
*/
void Client::setCom(vector<Commande> c){
    for(unsigned int i = 0; i< c.size(); i++){
        com.push_back(c[i]);
    }
}


/** < @brief Choisi des recettes aleatoire du menu pour le donner au client 
 * @param carte contient toutes les recettes possibles
*/
void Client::commandeAleatoire(const vector<Commande> &carte){  

    unsigned int random1, random2, random3;
    unsigned int min1 = 0;
    unsigned int max1 = 5;
    unsigned int min2 = 6;
    unsigned int max2 = 8;  

    unsigned int frites = 6;
    unsigned int soda = 7;
    unsigned int jus = 8;
  

    string recette1, recette2, recette3, nom1, nom2, nom3;
    unsigned int prix1, prix2, prix3;

        random1 = rand()%(max1 - min1 + 1) + min1; // nombre aleatoire entre 0 et 5
        nom1 = carte[random1].getNom();
        prix1 = carte[random1].getPrix();
        Commande c1(nom1, prix1);
        com.push_back(c1);

            random2 = rand()%(max2 - min2 + 1) + min2; // nombre aleatoire entre 6 et 9
            nom2 = carte[random2].getNom();
            prix2 = carte[random2].getPrix();
            Commande c2(nom2, prix2);
            com.push_back(c2);
            
                random3 = rand()%(max2 - min2 + 1) + min2; // nombre aleatoire entre 6 et 9

                if(random3 == random2){ // Il ne fait rien !        
                }

                else{
                    if(random3 == frites){
                        nom3 = carte[frites].getNom();
                        prix3 = carte[frites].getPrix();
                        Commande c3(nom3, prix3);
                        com.push_back(c3);
                    }
                    else{
                        if(random3 == soda && random2 != jus){
                            nom3 = carte[soda].getNom();
                            prix3 = carte[soda].getPrix();
                            Commande c3(nom3, prix3);
                            com.push_back(c3);
                        }
                        else{
                            if(random3 == jus && random2 != soda){
                                nom3 = carte[jus].getNom();
                                prix3 = carte[jus].getPrix();
                                Commande c3(nom3, prix3);
                                com.push_back(c3);
                            }
                            /*else{
                                nom3 = carte[rien].getNom();
                                prix3 = carte[rien].getPrix();
                                Commande c3(nom3, prix3);
                                commandeAl.push_back(c3);
                                cout << "recette3 : " << commandeAl[2] << endl;
                            }  */ 
                        }
                    }
                }

}

/** < @brief Procedure qui calcule le prix que le client doit payer */
void Client::calculePrix(){
    prixTot = 0;
    for(unsigned int i = 0; i<com.size(); i++){
        prixTot = prixTot + com[i].getPrix();
    }
}

/** < @brief Procedure: qui efface un element d'indice j du vecteur com
 *  @param j indice de la commande que l'on veut effacer 
*/
void Client::erase(int j){
    com.erase( com.begin()+j);
}