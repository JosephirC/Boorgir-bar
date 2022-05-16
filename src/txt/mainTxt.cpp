#include "winTxt.h"
#include "txtJeu.h"
#include "../Jeu.h"

/** < @brief fonction principale de l'affichage txt */
int main ( int argc, char** argv ) {
	srand(time(NULL));
    termClear();
	

	Temps t(400);
	//int test;
	//test = t.tempsRestant;
	//cout<< clock();

	
	Jeu j;

	boucleJeu(j);

    termClear();
	return 0;
}
