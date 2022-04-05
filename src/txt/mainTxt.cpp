#include "winTxt.h"
#include "txtJeu.h"
#include "../Jeu.h"

int main ( int argc, char** argv ) {
	srand(time(NULL));
    termClear();
	cout<< "Bienvenu a Boorgir Bar!"<<endl<<endl;
	cout<< "M: Menu"<<endl;
	cout<< "C: Client"<<endl;
	cout<< "Q: Quit"<<endl;

	cout<< "Aide: Vous pouvez utiliser la carte menu pour trouver les touches des ingredients."<<endl<<endl;
		

	Jeu j;
	vector<Client> tabC;
	j.creationClient(4, tabC);

	Commande com;
	vector<Commande> carte;
	com.chargerCarte(carte, "./txt/Carte.txt");
	
	vector<Recette> R;

	txtBoucle(j,carte,tabC,R);
    termClear();
	return 0;
}
