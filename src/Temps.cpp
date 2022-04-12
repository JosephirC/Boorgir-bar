#include "Temps.h"
#include <time.h>
#include <iostream>
#include <stdio.h>

using namespace std;

Temps::Temps(int t){
    temps = t;
    t1 = clock();
}

Temps::~Temps(){ // Est ce qu'on a besoin d'un destructeur de temps ? 
    
}


int Temps::tempsRestant(){
    return temps - (clock() - t1);
}

bool Temps::tempsAtteint(){
    return tempsAtteint() <=0;

}


