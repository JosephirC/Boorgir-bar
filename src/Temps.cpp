#include "Temps.h"
#include <time.h>
#include <iostream>
#include <stdio.h>

using namespace std;

/** < @brief un constructeur de Temps */
Temps::Temps(){

}

/** < @brief un constructeur de Temps */
Temps::Temps(double t){
    temps = t;
    t1 = clock()/(double)CLOCKS_PER_SEC;
}

/** < @brief destructeur de Temps */
Temps::~Temps(){ // Est ce qu'on a besoin d'un destructeur de temps ?     
}

/** < @brief accesseur qui recupere le temps*/
double Temps::getTemps() const{
     return temps;
 }

/** < @brief mutateur qui recupere le temps */
void Temps::setTemps(double t){
    temps = t;
    t1 = clock()/(double)CLOCKS_PER_SEC;
 } 

/** < @brief accesseur qui recupere le tick */
 clock_t Temps::getClock() const{
     return t1;
 }


//double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
/** < @brief retourne le temps passe de la partie */
double Temps::tempsPasse(){
    return (clock()/(double) CLOCKS_PER_SEC - t1);   //used to be clock - t1
}

/** < @brief retourne le temps restant de la partie */
double Temps::tempsRestant(){
    return temps - (clock()/(double) CLOCKS_PER_SEC - t1);   //used to be clock - t1
}

/** < @brief le temps total donne de la partie */
bool Temps::tempsAtteint(){
    return tempsRestant() <= 0;

}


