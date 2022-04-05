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
	int i=strtol("1",NULL,10);
	cout << i;
	

	Jeu j;
	vector<Client> tabC;
	j.creationClient(4, tabC);

	cout<<"ok creation" << endl;

	Commande com;
	vector<Commande> carte;
	com.chargerCarte(carte, "./txt/Carte.txt");
	
	//vector<Commande> carte;
	//carte=j.getCarte();
	vector<Recette> R;

	
	txtBoucle(j,carte,tabC,R);

	cout << "bro ? " << endl;
	
    termClear();
	return 0;
}
