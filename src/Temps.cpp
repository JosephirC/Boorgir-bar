#include "Temps.h"
#include <time.h>
#include <iostream>
#include <stdio.h>

using namespace std;

Temps::Temps(){

}

Temps::Temps(double t){
    temps = t;
    t1 = clock()/(double)CLOCKS_PER_SEC;
}

Temps::~Temps(){ // Est ce qu'on a besoin d'un destructeur de temps ?     
}

double Temps::getTemps() const{
     return temps;
 }

void Temps::setTemps(double t){
    temps = t;
    t1 = clock()/(double)CLOCKS_PER_SEC*100;
 } 

 clock_t Temps::getClock() const{
     return t1;
 }


//double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
double Temps::tempsPasse(){
    return (clock()/(double) CLOCKS_PER_SEC*100 - t1);   //used to be clock - t1
}

double Temps::tempsRestant(){
    return temps - (clock()/(double) CLOCKS_PER_SEC - t1);   //used to be clock - t1
}

bool Temps::tempsAtteint(){
    return tempsRestant() <=0;

}


