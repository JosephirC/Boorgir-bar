#include "winTxt.h"
#include "txtJeu.h"
#include "../Jeu.h"

int main ( int argc, char** argv ) {
    termClear();
	Jeu j;
	Commande com;
	vector<Commande> carte;
	com.chargerCarte(carte, "./txt/Carte.txt");
	
	//vector<Commande> carte;
	//carte=j.getCarte();
	txtBoucle(j,carte);
    termClear();
	return 0;
}
