#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"


#include "../Jeu.h"

void txtAff(WinTXT & win, const Jeu & jeu) {
	
}

/* 
bool selectIng(vector <Commande> carte, Commande commande){
	bool result = false;
	for (unsigned int i = 0; i < v.size(); i++) // unsigned int i = 0; i < v.size(); i++ présentent le risque que le compilateur ne sorte pas de la boucle le calcul de v.size() 
	{
        if (carte[i]==commande){
			result = true;
			break;
		}
	}
	return result;
}
*/




void affCarte(vector <Commande> carte){
	cout<< "----- Voici la Carte -------"<<endl;
	for (unsigned int i = 0; i < carte.size(); i++) // unsigned int i = 0; i < v.size(); i++ présentent le risque que le compilateur ne sorte pas de la boucle le calcul de v.size() 
	{
		cout<<i<<" "<<carte[i].getNom()<<" "<<carte[i].getPrix()<< "$ "<<endl;
	}
}

void affClient(vector <Client> tab){
	cout<< "----- Voici les client -------"<<endl;
	unsigned int i,j;
	for (i = 0; i < tab.size(); i++) // unsigned int i = 0; i < v.size(); i++ présentent le risque que le compilateur ne sorte pas de la boucle le calcul de v.size() 
	{
		cout<<"Le client "<<tab[i].getIdC()<<" veut: "<<endl;
		//for (j = 0; j < 3; j++) {              //ici il faut afficher la commande du client
		//	cout<<tabC[i].getCom().getNom();
			
		//}
		cout<<tab[i].getPrix()<< "$ "<<endl;
	}
}


Commande txtChoixIng(int c,vector <Commande> carte){   //c' est getch
	return carte[c];
}

void txtChoixIngredient(char c){
	
}



void txtBoucle (Jeu & jeu,vector<Commande> carte) {
	
	bool ok = true;
	char c;
	cout<<"boucle";
	WinTXT win;


	do {
	    //txtAff(win,jeu);
		
        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32
		
    	c=win.getCh();

		
		switch(c)
		{
			case 'h':
				cout<<"enter";
				affCarte(carte);
				break;

			case 'c':
				affClient(jeu.tabC);
				break;

			case 'q':
				ok = false;
				break;

		}
			

	} while (ok);

}
