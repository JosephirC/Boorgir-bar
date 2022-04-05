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
	cout<< "------------ Voici les clients -----------"<<endl;
	unsigned int i,j; //j
	for (i = 0; i < tab.size(); i++) // unsigned int i = 0; i < v.size(); i++ présentent le risque que le compilateur ne sorte pas de la boucle le calcul de v.size() 
	{
		cout<<"Le client "<<tab[i].getIdC()<<" veut: "<<endl;
		for (j = 0; j < 2; j++) {              //ici il faut afficher la commande du client
			
			cout<<" "<<tab[i].com[j].getNom() <<" ";
			
		}
		cout<<tab[i].getPrix()<< "$ "<<endl;
	}
}


Commande txtChoixIng(int c,vector <Commande> carte){   //c
	return carte[c];
}

void theChoixIngredient(char c){
	//int i=strtol("1",NULL,10)
	//int i=strtol("c",NULL,10);
	

}





void txtBoucle (Jeu & jeu,vector<Commande> carte,vector<Client> &tab,vector<Recette> &R) {
	
	bool ok = true;
	char c;
	cout<<"boucle";
	WinTXT win;
	unsigned int id;


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
				affClient(tab);
				break;

			//case '0':
			//	txtChoixIng(0,carte);
			//	break;

			case 'q':
				ok = false;
				break;
			
			case '0':                //Je voulais faire une boucle mais switch ne me permet pas. A voir :)
				cout << "B_Steak_Salade_Tomate selectionne "<<endl;
				jeu.compareRecette(R,tab,"B_Steak_Salade_Tomate",id);
				break;
			case '1':
				cout << "B_Steak_Salade_Tomate_Ketchup selectionne "<<endl;
				jeu.compareRecette(R,tab,"B_Steak_Salade_Tomate_Ketchup",id);
				break;
			case '2':
				cout << "B_Steak_Salade_Tomate_Mayo selectionne "<<endl;
				jeu.compareRecette(R,tab,"B_Steak_Salade_Tomate_Mayo",id);
				break;
			case '3':
				cout << "HD_Saucisse selectionne "<<endl;
				jeu.compareRecette(R,tab,"HD_Saucisse",id);
				break;
			case '4':
				cout << "HD_Saucisse_Ketchup selectionne "<<endl;
				jeu.compareRecette(R,tab,"HD_Saucisse_Ketchup",id);
				break;	
			case '5':
				cout << "HD_Saucisse_Mayo selectionne "<<endl;
				jeu.compareRecette(R,tab,"HD_Saucisse_Mayo",id);
				break;
			case '6':
				cout << "Frites selectionne "<<endl;
				jeu.compareRecette(R,tab,"Frites",id);
				break;
			case '7':
				cout << "Soda selectionne "<<endl;
				jeu.compareRecette(R,tab,"Soda",id);
				break;
			case '8':
				cout << "Jus selectionne "<<endl;
				jeu.compareRecette(R,tab,"Jus",id);
				break;

		}
			

	} while (ok);

}
