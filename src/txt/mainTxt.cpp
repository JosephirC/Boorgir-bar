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

	Temps t(400);
	//int test;
	//test = t.tempsRestant;
	//cout<< clock();

	Jeu j;
	j.chargerCarte(j.carte, "./txt/Carte.txt");
	j.creationClient(4,j.tabClient ,j.carte);

	j.getObj().choixNiveau(1);
	//cout<< j.getObj().finJeu()<<endl;
	cout<<endl<<"ho " <<j.getObj().Temp.getTemps()<<endl;
	cout<<endl<<"passe2 " <<j.getObj().Temp.tempsPasse()<<endl;
	cout<<endl<<"passe1 " <<j.getObj().Temp.tempsRestant()<<endl;
	cout<<endl<<"passe3 " <<j.getObj().Temp.tempsPasse()<<endl;
	cout<<endl<<"passe1 " <<j.getObj().Temp.tempsRestant()<<endl;
	cout<<endl<<"passe4 " <<j.getObj().Temp.tempsPasse()<<endl;
	cout<<endl<<"passe1 " <<j.getObj().Temp.tempsRestant()<<endl;
	cout<<endl<<"passe5 " <<j.getObj().Temp.tempsPasse()<<endl;
	cout<<endl<<"passe1 " <<j.getObj().Temp.tempsRestant()<<endl;
	cout<<endl<<"passe6 " <<j.getObj().Temp.tempsPasse()<<endl;
	vector<Recette> R;
	

	txtBoucle(j,R);
    termClear();
	return 0;
}
