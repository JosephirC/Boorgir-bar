#ifndef _TEMPS_H
#define _TEMPS_H

#include <string>
#include <time.h>
#include <iostream>

using namespace  std;

class Temps{

    private :

        /** < @param t1 Tick du debut */
        clock_t t1;    
        /** < @param temps Temps total de l'evenement que nous avons defini */
        double temps;  

    public :

        /** < @brief Constructeur de Temps */
        Temps(); 

        /** < @brief Constructeur de Temps 
         *  @param temps temps du jeu
        */
        Temps(double temps); 
        /** < @brief Destructeur de Temps */
        ~Temps();

        /** < @brief Accesseur : recupere le temps*/
        double getTemps() const;
        /** < @brief Mutateur : modifie le temps 
         *  @param t temps du jeu
        */
        void setTemps(double t);
        /** < @brief Accesseur : recupere le tick */
        clock_t getClock() const;
        /** < @brief Mutateur : modifie le tick */
        void setClock();



        /** < @brief Retourne le temps restant de la partie */
        double tempsRestant();
        /** < @brief Retourne le temps passe de la partie */
        double tempsPasse();
        /** < @brief Temps total donne de la partie */
        bool tempsAtteint(); 


};

#endif