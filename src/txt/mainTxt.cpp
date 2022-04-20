#include "winTxt.h"
#include "txtJeu.h"
#include "../Jeu.h"

int main ( int argc, char** argv ) {
	//srand(time(NULL));
    termClear();
	cout<< "Bienvenu a Boorgir Bar!"<<endl<<endl;
	cout<< "M: Menu"<<endl;
	cout<< "C: Client"<<endl;
	cout<< "Q: Quit"<<endl;

	cout<< "Aide: Vous pouvez utiliser la carte menu pour trouver les touches des ingredients."<<endl<<endl;
		

	Jeu j;
	j.chargerCarte(j.carte, "./txt/Carte.txt");
	j.creationClient(4,j.tabClient ,j.carte);

	vector<Recette> R;

	txtBoucle(j,R);
    termClear();
	return 0;
}
