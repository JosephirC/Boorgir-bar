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

void affIng(vector<Ingredient> tabIng){
	cout<<"----------Voici tous les Ingredients----------"<<endl;
	for(unsigned int i=0 ; i<tabIng.size(); i++){
		cout<<"Numero " <<i <<": "<<tabIng[i].getNom()<<endl;
	}
}


void affClient(vector <Client> tab){
	cout<<endl<< "------------ Voici les clients -----------"<<endl;
	unsigned int i,j; //j
	for (i = 0; i < tab.size(); i++) // unsigned int i = 0; i < v.size(); i++ présentent le risque que le compilateur ne sorte pas de la boucle le calcul de v.size() 
	{
		cout<<"Le client "<<tab[i].getIdC()<<" veut:";
		for (j = 0; j < tab[i].com.size(); j++) {              //ici il faut afficher la commande du client
			
			cout<<" "<<tab[i].com[j].getNom() <<" ";
			
		}
		cout<<" et doit payer "<<tab[i].getPrix()<< "$ "<< endl;
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

void affAide(){
	cout<< "M: Menu"<<endl;
	cout<< "C: Client"<<endl;
	cout<< "I: Ingredient"<<endl;
	cout<< "F: Pour preparer la nourriture sur le bar"<<endl;
	cout<< "D: Pour donner la nourriture au client"<<endl;
	cout<< "B: Pour afficher le bar"<<endl;
	cout<< "A: Aide"<<endl;
	cout<< "Q: Quit"<<endl;
}





void txtBoucle (Jeu &jeu, vector<Recette> &R) {
	
	bool ok = true;
	//bool okk = true;
	char c;
	//cout<<"boucle";
	WinTXT win;
	//unsigned int id;
	string ingred,ingerdTmp;
	int i;


	do {

		
			//txtAff(win,jeu);
			//termClear();
			
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

				case 'p':
					affRecette(jeu.tabRec);
					break;
					
				case 'i':
					affIng(jeu.tabIng);
					break;


				case 'q':
					ok = false;
					break;

				case 'a':
					affAide();
					break;
				
					
				case 'f':
					cout<<"Quel ingredient? ";
					cin>>ingred;
					cout<<" "<< jeu.tabIng[stoi(ingred)].getNom() << " Ajouter a quel bar de preparation? ";
					do{
						cin>>i;
						if(i<1 && i>4) cout<<"I doit etre entre 1 et 4. Vous avez choisi le numero "<<i<<endl;
						
					}while(i<1 && i>4);
					cout << "La preparation sur la case: "<<i<<endl;
					//jeu.compareRecette(R,jeu.tabClient,"Soda",id);
					ingerdTmp = jeu.PreparerCommande(jeu.tabIng[stoi(ingred)].getNom(),i);
					
					
					break;
				case 'g':
					unsigned int id;
					jeu.effaceRecette(jeu.tabClient,id,ingerdTmp);

				case 't':
					affTabPrep(jeu.tabPrep);
					break;

			}
		
		
	} while (ok);

}
