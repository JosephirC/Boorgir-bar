#ifndef _OBJECTIF_H
#define _OBJECTIF_H

#include "Temps.h"
#include <string>
#include <iostream>

using namespace  std;

class Objectif{

    private :
        
        int Argent;
        Temps evolTemp;

    public :
        Temps Temp;
        
        Objectif();

        ~Objectif();

        /*double getTemps() const;
        void setTemps(Temps &t);*/
        unsigned int getArgent() const;

        void choixNiveau(int choix);

        bool objAtteint(Temps temps_donnee); // renvoie vraie si l'objectif de la partie est atteint
        bool finJeu() const;

};

#endif