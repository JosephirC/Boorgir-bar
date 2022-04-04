#include "winTxt.h"
#include "txtJeu.h"
#include "../Jeu.h"

int main ( int argc, char** argv ) {
    termClear();
	cout<< "Bienvenu a Boorgir Bar"<<endl;
	cout<< "h: help carte"<<endl;
	cout<< "c: client"<<endl;
	cout<< "q: quit"<<endl;

	Jeu j;

	j.creationClient(4);
	cout<<"ok creation";

	Commande com;
	vector<Commande> carte;
	com.chargerCarte(carte, "./txt/Carte.txt");
	
	//vector<Commande> carte;
	//carte=j.getCarte();

	


	txtBoucle(j,carte);
    termClear();
	return 0;
}
