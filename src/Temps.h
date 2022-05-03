#ifndef _TEMPS_H
#define _TEMPS_H

#include <string>
#include <time.h>
#include <iostream>

using namespace  std;

class Temps{

    private :

        /** < @brief le tick du debut */
        clock_t t1;    
        /** < @brief //temps total de l'evenement que nous avons defini */
        double temps;  

    public :

        /** < @brief un constructeur de Temps */
        Temps(); // useless, ps de sens

        /** < @brief constructeur de Temps */
        Temps(double temps); // Dans le .cpp on fait temps = t 
        // on fait appelle a la fonction clock(), on la stocque dans t1, 

        /** < @brief destructeur de Temps */
        ~Temps();

        /** < @brief accesseur qui recupere le temps*/
        double getTemps() const;
        /** < @brief mutateur qui recupere le temps */
        void setTemps(double t);
        /** < @brief accesseur qui recupere le tick */
        clock_t getClock() const;

        /** < @brief retourne le temps restant de la partie */
        double tempsRestant();
        // temps - (t2 - t1)
        /** < @brief retourne le temps passe de la partie */
        double tempsPasse();

        /** < @brief le temps total donne de la partie */
        bool tempsAtteint(); // temps_donne - (t2 - t1) avec t2 le temps qui se calcule au debut de la partie

      
        //je fais un appelle a clock, je fais la diff par rapport au t1 , pour savoir le temps ecoule, et puis je fais temps - t1 
        //on divise pour enlever les decimales puis on fait la diff
        //tempsatteint appelle tempsRestant
        //vrai si <0




        
    


        


};

#endif