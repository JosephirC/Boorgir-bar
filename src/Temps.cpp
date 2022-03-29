#include "Temps.h"
#include <time.h>
#include <iostream>

using namespace std;

Temps::Temps(int t){
    temps = t;
    t1 = clock();
}

Temps::~Temps(){ // Est ce qu'on a besoin d'un destructeur de temps ? 
    
}

/*int ::Temps::tempsRestant(t1, int t2){
    return temps - (t2 - t1);
}

bool Temps::tempsAtteint(){
    //t1 = clock();

}*/