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

//double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;


double Temps::tempsRestant(){
    return temps - (clock()/(double) CLOCKS_PER_SEC - t1);
}

bool Temps::tempsAtteint(){
    return tempsRestant() <=0;

}


