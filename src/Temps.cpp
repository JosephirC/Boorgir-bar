#include "Temps.h"
#include <time.h>
#include <iostream>
#include <stdio.h>

using namespace std;

/** < @brief Constructeur de Temps */
Temps::Temps(){

}

/** < @brief Constructeur de Temps 
 *  @param t temps du jeu
*/
Temps::Temps(double t){
    temps = t;
    t1 = clock()/(double)CLOCKS_PER_SEC;
}

/** < @brief Destructeur de Temps */
Temps::~Temps(){  
}

/** < @brief Accesseur : recupere le temps*/
double Temps::getTemps() const{
     return temps;
 }

/** < @brief Mutateur : modifie le temps 
 *  @param t temps du jeu
*/
void Temps::setTemps(double t){
    temps = t;
    t1 = clock()/(double)CLOCKS_PER_SEC;
 } 

/** < @brief Accesseur : recupere le tick */
 clock_t Temps::getClock() const{
     return t1;
 }

/** < @brief Mutateur : modifie le tick */
 void Temps::setClock(){
     t1 = clock()/(double)CLOCKS_PER_SEC;
 }


/** < @brief Retourne le temps passe de la partie */
double Temps::tempsPasse(){
    return (clock()/(double) CLOCKS_PER_SEC - t1);   //used to be clock - t1
}

/** < @brief Retourne le temps restant de la partie */
double Temps::tempsRestant(){
    return temps - (clock()/(double) CLOCKS_PER_SEC - t1);   //used to be clock - t1
}

/** < @brief Temps total donne de la partie */
bool Temps::tempsAtteint(){
    return tempsRestant() <= 0;

}


