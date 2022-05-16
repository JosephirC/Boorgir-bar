#ifndef _OBJECTIF_H
#define _OBJECTIF_H

#include "Temps.h"
#include <string>
#include <iostream>

using namespace  std;

class Objectif{

    private :
        
        /** < @param Argent Argent qu el'on doit atteindre au cours de la partie */
        int Argent;


        /** < @param evolTemp Evolution du temps */
        //Temps evolTemp;
         
         /** < @param T Temps de la partie */
        Temps T;

    public :

       
        
        /** < @brief Constructeur de Objectif */
        Objectif();

        /** < @brief Destructeur de Objectif */
        ~Objectif();

        /** < @brief Accesseur : recupere le temps */
        Temps getTemps() const;
        /** < @brief Mutateur : modifie le temps 
         *  @param t temps du jeu
        */
        void setTemps(Temps &t);
        
        /** < @brief Accesseur : recupere l'argent gagne pendant la partie */
        unsigned int getArgent() const ;
        /** < @brief Permet de selectionner le niveau voulu 
         *  @param choix choisir le niveau de difficulte
        */
        void choixNiveau(unsigned int choix);

        /** < @brief Renvoie vraie si l'objectif de la partie est atteint 
         *  @param temps_donnee temps donnee pour une partie
        */
        bool objAtteint(Temps temps_donnee); 
        /** < @brief Permet d'arreter la partie */
        bool finJeu()const;

};

#endif