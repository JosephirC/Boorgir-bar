#ifndef _OBJECTIF_H
#define _OBJECTIF_H

#include "Temps.h"
#include <string>
#include <iostream>

using namespace  std;

class Objectif{

    private :
        
        /** < @brief argent qu el'on doit atteindre au cours de la partie */
        int Argent;


        /** < @brief evolution du temps */
        Temps evolTemp;
         
         /** < @brief temps de la partie */
        Temps T;

    public :

       
        
        /** < @brief constructeur de Objectif */
        Objectif();

        /** < @brief destructeur de Objectif */
        ~Objectif();

        Temps getTemps() const;
        void setTemps(Temps &t);
        
        /** < @brief  retourne l'argent gagne pendant la partie */
        unsigned int getArgent() const;
        /** < @brief permet de selectionner le niveau voulu */
        void choixNiveau(unsigned int choix);

        /** < @brief renvoie vraie si l'objectif de la partie est atteint */
        bool objAtteint(Temps temps_donnee); 
        /** < @brief permet d'arreter la partie */
        bool finJeu() const;

};

#endif