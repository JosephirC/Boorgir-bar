#ifndef _ARGENT_H
#define _ARGENT_H


#include <string>
#include <iostream>

using namespace  std;

class Argent{

    private :
    
        int argent;

    public :

        Argent();

        Argent(unsigned int ar;); // dans le .cpp on fait argent = ar

        ~Argent();

        int sommeArgent(int cash); // permet d'additioner les paiements

        bool argentAtteint(); // renvoie vraie si l'argent attendu de la partie est atteint 
        // BLANC AU DEBUT, VERT QUAND C ATTEINT

};

#endif