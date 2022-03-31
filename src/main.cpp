#include "Jeu.h"
//#include "Recette.h"
//#include "Ingredient.h"
//#include "Client.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    //int id, age;
    //string name;
    /*string name;
    int price, pos, tempscuisson;
    ifstream file("test.txt");
    if(file.is_open())
    {
        string line;
		//getline(file, line);
        while(file >> name >> price >> pos >> tempscuisson)
        {
            cout << name << " " << price << " " << pos<< " " << tempscuisson << endl;
        }

        file.close();
    }
    else cout << "FAILED..." << endl;*/


    /*ifstream fileIng("./txt/test.txt");
    string nomIng;
    int prix, pos, tempsCuisson;
    if(fileIng.is_open()){

        //ignorer la premiere ligne
		//string line;
		//getline(fileIng, line);

        while(fileIng >> nomIng >> prix >> pos >> tempsCuisson){
            //Ingredient ing(nomIng, prix, pos, 10, tempsCuisson);
            //ingVec.push_back(ing);
            cout << nomIng << " " << prix << " " << pos << " " << tempsCuisson << endl;
        }


        fileIng.close();
    }

    else 
        cout << "Failed to open file..." << endl;*/
    
    Jeu j1(0,0);
    //string ingredient = "Salade";
    j1.chargerIngredient("./txt/Ingredient.md");
    

}