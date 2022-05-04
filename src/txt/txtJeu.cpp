#include <iostream>
#include <stdlib.h>
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
	cout<<endl<< "----- Voici la Carte -------"<<endl;
	for (unsigned int i = 0; i < carte.size(); i++) // unsigned int i = 0; i < v.size(); i++ présentent le risque que le compilateur ne sorte pas de la boucle le calcul de v.size() 
	{
		cout<<i<<" "<<carte[i].getNom()<<" "<<carte[i].getPrix()<< "$ "<<endl;
	}
}

void affRecette(vector<Recette> tabRec){
	for(unsigned int i=0 ; i<tabRec.size(); i++){
		cout<<tabRec[i].getNom()<< " de prix: "<<tabRec[i].getPrix()<<" dont les ingredients sont |";
		for(unsigned int j=0;j<tabRec[i].getTab().size();j++){
			cout<< tabRec[i].getTab()[j]<< " | ";
		}
		cout<<endl;
	}
}

void affClient(vector <Client> tab){
	cout<<endl<< "------------ Voici les clients -----------"<<endl;
	unsigned int i,j; //j
	for (i = 0; i < tab.size(); i++) // unsigned int i = 0; i < v.size(); i++ présentent le risque que le compilateur ne sorte pas de la boucle le calcul de v.size() 
	{
		cout<<"Le client "<<tab[i].getIdC()<<" veut: "<<endl;
		for (j = 0; j < tab[i].com.size(); j++) {              //ici il faut afficher la commande du client
			
			cout<<" "<<tab[i].com[j].getNom() <<" ";
			
		}
		cout<<tab[i].getPrix()<< "$ "<< endl <<endl;
	}
	cout << endl;
}

void affTabPrep(string tabPrep[4]){
	for(int i=0;i<4;i++){
		cout<<"Bar de preparation "<<i<<": " <<tabPrep[i]<<endl;
	}
	cout<<endl;
}


Commande txtChoixIng(int c,vector <Commande> carte){   //cHint
	return carte[c];
}

void theChoixIngredient(char c){
	//int i=strtol("1",NULL,10)
	//int i=strtol("c",NULL,10);
	

}





void txtBoucle (Jeu &jeu, vector<Recette> &R) {
	
	bool ok = true;
	char c;
	//cout<<"boucle";
	WinTXT win;
	//unsigned int id;
	string ingred,ingerdTmp;
	int i=0;


	do {
	    //txtAff(win,jeu);
		
        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32
		
    	c=win.getCh();

		//cout<<endl<<"passe1 " <<jeu.getObj().Temp.tempsRestant()<<endl;
		//cout<< jeu.getObj().Temp.tempsAtteint()<<endl;
		
		//win.clear();

		switch(c)
		{
			case 'm':
				affCarte(jeu.carte);
				break;

			case 'c':
				affClient(jeu.tabClient);
				break;

			case 'u':
				affRecette(jeu.tabRec);
				break;

			//case '0':
			//	txtChoixIng(0,carte);
			//	break;

			case 'q':
				ok = false;
				break;
			
			/*case '0':                //Je voulais faire une boucle mais switch ne me permet pas. A voir :)
				cout << "B_Steak_Salade_Tomate selectionne "<<endl;
				//jeu.compareRecette(R,jeu.tabClient,"B_Steak_Salade_Tomate",id);
				//jeu.effaceRecette(jeu.tabClient,id,"B_Steak_Salade_Tomate");
				break;
			case '1':
				cout << "B_Steak_Salade_Tomate_Ketchup selectionne "<<endl;
				//jeu.compareRecette(R,jeu.tabClient,"B_Steak_Salade_Tomate_Ketchup",id);
				break;
			case '2':
				cout << "B_Steak_Salade_Tomate_Mayo selectionne "<<endl;
				//jeu.compareRecette(R,jeu.tabClient,"B_Steak_Salade_Tomate_Mayo",id);
				break;
			case '3':
				cout << "HD_Saucisse selectionne "<<endl;
				//jeu.compareRecette(R,jeu.tabClient,"HD_Saucisse",id);
				break;
			case '4':
				cout << "HD_Saucisse_Ketchup selectionne "<<endl;
				//jeu.compareRecette(R,jeu.tabClient,"HD_Saucisse_Ketchup",id);
				break;	
			case '5':
				cout << "HD_Saucisse_Mayo selectionne "<<endl;
				//jeu.compareRecette(R,jeu.tabClient,"HD_Saucisse_Mayo",id);
				break;
			case '6':
				cout << "Frites selectionne "<<endl;
				//jeu.compareRecette(R,jeu.tabClient,"Frites",id);
				break;
			case '7':
				cout << "Soda selectionne "<<endl;
				//jeu.compareRecette(R,jeu.tabClient,"Soda",id);
				break;
			case '8':
				cout << "Jus selectionne "<<endl;
				//jeu.compareRecette(R,jeu.tabClient,"Jus",id);
				break;
				*/
			case 'f':
				cin>>ingred;
				cout << ingred << " Ajouter a quelle case? "<<endl;
				while(i<1 && i>1){
					cin>>i;
					cout<<"I doit etre entre 1 et 4 votre i est: "<<i<<endl;
				}
				cout << " La preparation sur la case: "<<i<<endl;
				//jeu.compareRecette(R,jeu.tabClient,"Soda",id);
				ingerdTmp = jeu.PreparerCommande(ingred,i);
				break;
			case 'g':
				unsigned int id;
				jeu.effaceRecette(jeu.tabClient,id,ingerdTmp);
			case 'p':
				affTabPrep(jeu.tabPrep);
				break;

		}
			
		
	} while (ok);

}
