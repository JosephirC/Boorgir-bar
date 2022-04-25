#ifndef _TEMPS_H
#define _TEMPS_H

#include <string>
#include <time.h>
#include <iostream>

using namespace  std;

class Temps{

    private :

        clock_t t1;    //le tick au debut
        double temps;  //temps toal de l'evenemt que nous avons defini

    public :

        Temps(); // useless, ps de sens

        Temps(double temps); // Dans le .cpp on fait temps = t 
        // on fait appelle a la fonction clock(), on la stocque dans t1, 

        ~Temps();

        double getTemps() const;
        void setTemps(double t);
        clock_t getClock() const;

        double tempsRestant();
        // temps - (t2 - t1)
        double tempsPasse();

        bool tempsAtteint(); // temps_donne - (t2 - t1) avec t2 le temps qui se calcule au debut de la partie

      
        //je fais un appelle a clock, je fais la diff par rapport au t1 , pour savoir le temps ecoule, et puis je fais temps - t1 
        //on divise pour enlever les decimales puis on fait la diff
        //tempsatteint appelle tempsRestant
        //vrai si <0




        
    


        


};

#endif