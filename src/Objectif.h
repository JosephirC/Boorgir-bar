#ifndef _OBJECTIF_H
#define _OBJECTIF_H

#include "Temps.h"
#include "Argent.h"
#include <string>
#include <iostream>

using namespace  std;

class Objectif{

    private :
  

    public :

        Objectif();

        ~Objectif();

        bool objAtteint(Temps temps_donnee, Argent argent); // renvoie vraie si l'objectif de la partie est atteint

};

#endif