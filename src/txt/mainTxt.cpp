#include "winTxt.h"
#include "txtJeu.h"
#include "../Jeu.h"

int main ( int argc, char** argv ) {
	srand(time(NULL));
    termClear();
	cout<< "Bienvenu a Boorgir Bar"<<endl;
	cout<< "h: help carte"<<endl;
	cout<< "c: client"<<endl;
	cout<< "q: quit"<<endl;

	Jeu j;
	vector<Client> tabC;
	j.creationClient(4, tabC);

	cout<<"ok creation" << endl;

	Commande com;
	vector<Commande> carte;
	com.chargerCarte(carte, "./txt/Carte.txt");
	
	//vector<Commande> carte;
	//carte=j.getCarte();

	
	txtBoucle(j,carte,tabC);

	cout << "bro ? " << endl;
	
    termClear();
	return 0;
}
