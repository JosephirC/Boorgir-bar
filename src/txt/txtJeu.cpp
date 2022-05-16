#include <iostream>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"


#include "../Jeu.h"


/** < @brief permet d'afficher la carte */
void affCarte(vector <Commande> carte){
	cout<<endl<< "----- Voici le Menu d'aujourd'hui -------"<<endl;
	for (unsigned int i = 0; i < carte.size(); i++) // unsigned int i = 0; i < v.size(); i++ présentent le risque que le compilateur ne sorte pas de la boucle le calcul de v.size() 
	{
		cout<<i<<" "<<carte[i].getNom()<<" "<<carte[i].getPrix()<< "$ "<<endl;
	}
}

/** < @brief affiche la recette d'une commande */
void affRecette(vector<Recette> tabRec){
	for(unsigned int i=0 ; i<tabRec.size(); i++){
		cout<<tabRec[i].getNom()<< " de prix: "<<tabRec[i].getPrix()<<" dont les ingredients sont |";
		for(unsigned int j=0;j<tabRec[i].getTab().size();j++){
			cout<< tabRec[i].getTab()[j]<< " | ";
		}
		cout<<endl;
	}
}

/** < @brief affiche les ingredients */
void affIng(vector<Ingredient> tabIng){
	cout<<"----------Voici tous les Ingredients----------"<<endl;
	for(unsigned int i=0 ; i<tabIng.size(); i++){
		cout<<"Numero " <<i <<": "<<tabIng[i].getNom()<<endl;
	}
}

/** < @brief permet d'afficher un client */
void affClient(vector <Client> tab){
	cout<<endl<< "------------ Voici les clients -----------"<<endl;
	unsigned int i,j; //j
	
	for (i = 0; i < tab.size(); i++) // unsigned int i = 0; i < v.size(); i++ présentent le risque que le compilateur ne sorte pas de la boucle le calcul de v.size() 
	{
		cout<<"Le client "<<tab[i].getIdC()<<" veut:";
		for (j = 0; j < tab[i].getCom().size(); j++) {              //ici il faut afficher la commande du client
			
			cout<<" "<<tab[i].getCom()[j].getNom() <<" ";
			
		}
		cout<<" et doit payer "<<tab[i].getPrix()<< "$ "<< endl;
	}
	cout << endl;
}

/** < @brief affiche le tableau de preparation */
void affTabPrep(string tabPrep[4]){
	cout<<endl<< "------------ Voici le Bar -----------"<<endl;
	for(int i=0;i<4;i++){
		cout<<"Bar de preparation "<<i<<": " <<tabPrep[i]<<endl;
	}
	cout<<endl;
}


//Commande txtChoixIng(int c,vector <Commande> carte){   //cHint
//	return carte[c];
//}

/** < @brief affiche l'aide du jeu */
void affAide(){
	cout<< "M: Menu"<<endl;
	cout<< "C: Client"<<endl;
	cout<< "I: Ingredient"<<endl;
	cout<< "B: Bar "<<endl;

	cout<< "F: Pour preparer la nourriture sur le bar (Find)"<<endl;
	cout<< "G: Pour donner la nourriture aux clients (Give)"<<endl;
	cout<< "D: Pour donner les accompagnement aux clients (Donner)"<<endl;
	
	cout<< "T: Temps restant"<<endl;
	cout<< "Y: Argent gagné et l'objectif "<<endl;
	cout<< "A: Aide"<<endl;
	cout<< "Q: Quit"<<endl<<endl;
}

/** < @brief prepare la commande avec les ingredients choisis, en txt */
void preparerCommandeTxt(int &i,long unsigned int &ingred,Jeu &jeu){
	do{

		cin.clear();
		cin.ignore();
		cout<<"-Quel ingredient? ";
		cin>>ingred;
	
	}while(cin.fail() || ingred<0 || ingred>jeu.getTabIng().size() );
	
	
	cout<<" "<<jeu.getTabIng()[ingred].getNom() << " -Ajouter a quel bar de preparation? ";
	
	do{
		cin.clear();
		cin.ignore();
		cin>>i;
		if(cin.fail() || i<0 || i>3) 
			cout<<endl<<"I doit etre entre 1 et 4. Vous avez choisi "<<i<< " Choisissez a nouveau:  ";
		
	}while(cin.fail() || i<0 || i>3);
	
	cout << "*La preparation sur la case: "<<i<<"."<<endl;
}

/** < @brief donne la commande au client choisi en txt */
void donnerCommandeTxt(unsigned int & IdCl, unsigned int & IdRec,Jeu &jeu){
	do{

		cin.clear();
		cin.ignore();
		cout<<"-Quel Case du bar? ";
		cin>>IdRec;
	
	}while(cin.fail() || IdRec<0 || IdRec>3 ); //tabPrep fixea 4
	
	
	cout<<" "<< jeu.tabPrep[IdRec] << " -Donner a quel client? ";
	
	do{
		cin.clear();
		cin.ignore();
		cin>>IdCl;
		if(cin.fail() || IdCl<1 || IdCl>4) 
			cout<<endl<<"I doit etre entre 1 et 4. Vous avez choisi "<<IdCl<< " Choisissez a nouveau:  ";
		
	}while(cin.fail() || IdCl<1 || IdCl>4 );
	

}

void donnerExtrasTxt(unsigned int & IdCl, string & s ,Jeu &jeu){
	 unsigned int IdRec;
	do{

		cin.clear();
		cin.ignore();
		cout<<"-Quel Accompagnement? 0=Frites 9=Jus 10=Soda ";
		cin>>IdRec;
	
	}while(cin.fail() || (IdRec!=0 && IdRec!=9 && IdRec!=10) ); //tabPrep fixea 4
	
	if(IdRec==0) s="Frites";
	if(IdRec==9) s="Jus";
	if(IdRec==10) s="Soda";

	cout<<"*Vous avez choisi "<<IdRec<<" "<<s<<endl;

	cout<<"-Donner a quel client? ";
	
	do{
		cin.clear();
		cin.ignore();
		cin>>IdCl;
		if(cin.fail() || IdCl<1 || IdCl>4) 
			cout<<endl<<"I doit etre entre 1 et 4. Vous avez choisi "<<IdCl<< " Choisissez a nouveau:  ";
		
	}while(cin.fail() || IdCl<1 || IdCl>4 );
	

}


/** < @brief prepare la commande avec les ingredients choisis, en txt */
void objectifDuJeu(unsigned int &Niveau,Jeu &jeu){
	do{

		cin.clear();
		cin.ignore();
		cout<<"-Quel Niveau veux-tu jouer? Tu as le choix entre 1,2,3!  :) "<<endl;
		cin>>Niveau;
	
	}while(cin.fail() || (Niveau!=1 && Niveau!=2 && Niveau!=3));
	
}

void afficheExplication() {
	cout<<"hii"<<endl;
}





void txtBoucleAcc (Jeu & jeu,bool &ok){

	char c;
	WinTXT win;
	unsigned int niv;
	unsigned int prixinit=0;
	




	cout<< "Bienvenu a Boorgir Bar!"<<endl<<endl;
	cout<< "C: Choisissez le Niveau que vous voulez en appuyant sur la touche C"<<endl;
	cout<< "A: Si vous êtes nouveau dans le jeu appuier sur A pour une explication du jeu"<<endl;

	do {
			
			#ifdef _WIN32
			Sleep(100);
			#else
			usleep(100000);
			#endif // WIN32
			
			c=win.getCh();
			switch(c)
			{
				case 'c':
					objectifDuJeu(niv,jeu);
					jeu.getObj().choixNiveau(niv);
					termClear();
					affAide();
					jeu.setAdditionArgent(prixinit);
					jeu.getObj().getTemps().setClock();

					ok = false;
					break;
				case 'a':
					afficheExplication();
					break;

			}
						
	} while (ok);	

}





void txtBoucleFin(Jeu &jeu, string g,bool &ok){
	int retry;
	WinTXT win;

	do{

		#ifdef _WIN32
		Sleep(100);
		#else
		usleep(100000);
		#endif // WIN32

		cout<<g<<endl;
		do{
			cin.clear();
			cin.ignore();
			cout<<"Si tu souhaite rejouer appuie sur 1 sinon pour quitter appuie sur 2 ";
			cin>>retry;
		}while(cin.fail() || (retry!=1 && retry!=2) );

		if (retry==1) break;
		if (retry==2) ok=false;

	} while (ok);
	termClear();
}







void txtBoucle(Jeu &jeu,bool &ok) {
	ok=true;

	char c;
	//cout<<"boucle";
	WinTXT win;
	//unsigned int id;
	string ingerdTmp,s;
	int i;
	long unsigned int ingred;
	unsigned int idCl,idRec;

	do {
			
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
				affCarte(jeu.getCarte());
				break;

			case 'c':
				affClient(jeu.getTabClient());
				break;

			case 'p':
				affRecette(jeu.getTabRec());
				break;
				
			case 'i':
				affIng(jeu.getTabIng());
				break;


			case 'a':
				affAide();
				break;
			
				
			case 'f':
				preparerCommandeTxt(i,ingred,jeu);
				ingerdTmp = jeu.PreparerCommande(jeu.getTabIng()[ingred].getNom(),i);
				break;

			case 'd':
				donnerExtrasTxt(idCl,s,jeu);
				idCl--;
				jeu.effaceExtras(idCl,s);
				jeu.money(idCl);
				

				break;

			case 'g':
				donnerCommandeTxt(idCl,idRec,jeu);
				idCl--;
				jeu.effaceRecette(idCl,idRec);
				jeu.money(idCl);

			case 'b':
				affTabPrep(jeu.tabPrep);
				break;

			case 't':
				cout<<"Le temps restant est de :"<<jeu.getObj().getTemps().tempsRestant()<<"!!!!"<<endl;
				break;
			case 'y':
				cout<<"Vous avez gagnez: "<<jeu.getAdditionArgent()<<"$ "<<endl;
				cout<<"Le but est de ramasser "<<jeu.getObj().getArgent()<<"$ "<<endl;
				break;

			case 'q':
				ok = false;
				break;
		}

		jeu.nouveauClient();

	
	}while( !jeu.getObj().finJeu() && !jeu.argentAtteint() && ok);

	if(jeu.getObj().finJeu()){
		cout<<"Sad!!!! ";
		usleep(100000);
		termClear();
		txtBoucleFin(jeu,"Oups, Perdu :/ le temps est ecoulé essaie une autre fois :) ",ok);
	}
	if(jeu.argentAtteint()){
		cout<<"BRAVOO!!!! ";
		usleep(100000);
		termClear();
		txtBoucleFin(jeu,"Bravo!!! Tu as terminer a temps! ",ok);
	}
		

}

void boucleJeu(Jeu & j){
	bool ok=true;
	do{

		txtBoucleAcc(j,ok);
		txtBoucle(j,ok);
	}while(ok);
}

