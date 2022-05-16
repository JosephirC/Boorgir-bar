#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include "sdlImage.h"
#include "../Temps.h"
#include "../Client.h"
//#include "../Jeu.h"
#include "../Commande.h"
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;


float temps () {
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS SDLJEU =============== //
sdlJeu::sdlJeu () : jeu() {
    /**********************Nombre d'ingredient ajoute par le joueur*************/

    
    nbrIngJ = 26;
    nbrClientServi =0;
    aServir="";
    newImage.setChemin("img/PainHD.png");
    
    image0.setChemin(newImage.getChemin());
    image0.setEmplacement(100);
    image0.setX(0);
    image0.setY(0);
    image0.setW(0);
    image0.setH(0);
    image0.setCase(0);

    image1.setChemin(newImage.getChemin());
    image1.setEmplacement(100);
    image1.setX(0);
    image1.setY(0);
    image1.setW(0);
    image1.setH(0);
    image1.setCase(0);

    image2.setChemin(newImage.getChemin());
    image2.setEmplacement(100);
    image2.setX(0);
    image2.setY(0);
    image2.setW(0);
    image2.setH(0);
    image2.setCase(0);

    image3.setChemin(newImage.getChemin());
    image3.setEmplacement(100);
    image3.setX(0);
    image3.setY(0);
    image3.setW(0);
    image3.setH(0);
    image3.setCase(0);

    /*******************Appelle a la classe de chargement des images*****************************/
    loadImg.chargerTxtImages("./txt/testSDL.txt");
    jeu.chargerRecette("./txt/test.txt");
    
    //Copiage de notre tab dynamique dans le tab dynamique de sdlJeu
    for(unsigned int i =0; i < loadImg.getLoadedImage().size(); i++){
        im.push_back(loadImg.getLoadedImage()[i]); 
    }

    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        cout << "No sound !!!" << endl;
        //SDL_Quit();exit(1);
        withSound = false;
    }
    else withSound = true;

    /************************** A VOIR CETTE PARTE **********************************/
	int dimx, dimy;
	dimx = 960;
	dimy = 960 +getNbrIngJ() * 66;

    //cout << "nbr ing apres dimy = " << getNbrIngJ() << endl;

    //cout << "dimy " << dimy << endl;
    //cout << "nbrIng " << getNbrIngJ() << endl;

    /********************************************************************************/

    // Creation de la fenetre
    window = SDL_CreateWindow("Boorgir-Bar", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    /**************************IMAGES***********************************************************/
    background.loadFromFile("./img/Backgr.png", renderer);
    
    

    for(unsigned int i =0; i< im.size(); i++){
        im[i].loadFromFile(im[i].getChemin().c_str(), renderer);
    }

    image0.loadFromFile(image0.getChemin().c_str(), renderer);
    image1.loadFromFile(image1.getChemin().c_str(), renderer);
    image2.loadFromFile(image2.getChemin().c_str(), renderer);
    image3.loadFromFile(image3.getChemin().c_str(), renderer);

    loadImgCommande();
    /************************************************************************************/
    /****************************************FONTS*******************************************/

    /*****************************************CHANGE FICHIER DE FONT*************************************/
    font = TTF_OpenFont("data/DejaVuSansCondensed.ttf",50);
    if (font == NULL)
        font = TTF_OpenFont("../data/DejaVuSansCondensed.ttf",50);
    if (font == NULL) {
            cout << "Failed to load DejaVuSansCondensed.ttf! SDL_TTF Error: " << TTF_GetError() << endl; 
            SDL_Quit(); 
            exit(1);
	}

    // FONT COLORS
	font_color.r = 0;
    font_color.g = 0;
    font_color.b = 0;

    /***********************************************SONS**************************************************/

    /*****************************************CHANGE FICHIER DE SON*************************************/
    if (withSound)
    {
        sound = Mix_LoadWAV("data/son.wav");
        if (sound == NULL) 
            sound = Mix_LoadWAV("../data/son.wav");
        if (sound == NULL) {
                cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() << endl; 
                SDL_Quit();
                exit(1);
        }
    }

}


/***********************************************************************************************************/

sdlJeu::~sdlJeu () {
    if (withSound) Mix_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/*void sdlJeu::sdlLoadImgFile(){

    //Charger le background
    background.loadFromFile("./img/Backgr.png", renderer);

    for(unsigned int i =0; i< im.size(); i++){
        im[i].loadFromFile(im[i].getChemin().c_str(), renderer);
    }

    image0.loadFromFile(image0.getChemin().c_str(), renderer);
    image1.loadFromFile(image1.getChemin().c_str(), renderer);
    image2.loadFromFile(image2.getChemin().c_str(), renderer);
    image3.loadFromFile(image3.getChemin().c_str(), renderer);
}*/

unsigned int sdlJeu::getNbrIngJ() const{
    //cout << "inside getnbr we have nbr = to " << im.size() << endl;
    return im.size() - nbrIngJ;
}

void sdlJeu::setNewImg(Image i){
    newImage.setNom(i.getNom());
    newImage.setEmplacement(100);
    newImage.setChemin(i.getChemin());
    newImage.setW(i.getW());
    newImage.setH(i.getH());
}

void sdlJeu::setIm0(Image i){
    image0.setNom(i.getNom());
    image0.setEmplacement(100);
    image0.setChemin(i.getChemin());
    image0.setW(i.getW());
    image0.setH(i.getH());
}

void sdlJeu::setIm1(Image i){
    image1.setNom(i.getNom());
    image1.setEmplacement(100);
    image1.setChemin(i.getChemin());
    image1.setW(i.getW());
    image1.setH(i.getH());
}

void sdlJeu::setIm2(Image i){
    image2.setNom(i.getNom());
    image2.setEmplacement(100);
    image2.setChemin(i.getChemin());
    image2.setW(i.getW());
    image2.setH(i.getH());
}

void sdlJeu::setIm3(Image i){
    image3.setNom(i.getNom());
    image3.setEmplacement(100);
    image3.setChemin(i.getChemin());
    image3.setW(i.getW());
    image3.setH(i.getH());
}

/*vector<Image> sdlJeu::getImageVec() const{
    return im;
}*/

void sdlJeu::sdlAff () {
	//Remplir l'ï¿½cran de blanc
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

	//const Terrain& ter = jeu.getConstTerrain();
	//const Pacman& pac = jeu.getConstPacman();
	//const Fantome& fan = jeu.getConstFantome();

    // Afficher les sprites des murs et des pastilles
	/*for (x=0;x<ter.getDimX();++x)
		for (y=0;y<ter.getDimY();++y)
			if (ter.getXY(x,y)=='#')
				im_mur.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
			else if (ter.getXY(x,y)=='.')
				im_pastille.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);*/



    /***************************AFFICHAGE DES IMAGE********************************/
	// Afficher le sprite de Pacman
	//im_pacman.draw(renderer,pac.getX()*TAILLE_SPRITE,pac.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);

	// Afficher le sprite du Fantome
	//im_fantome.draw(renderer,fan.getX()*TAILLE_SPRITE,fan.getY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);


    /*for(unsigned int i =0; i < loaded_im.size(); i++){
        loaded_im[i].draw(renderer, )
    }*/

    background.draw(renderer, 0,0, 960,960);    
    for(unsigned i =0; i<im.size(); i++){

        if(im[i].getEmplacement() < 7)
        {
            im[i].draw(renderer, im[i].getX(), im[i].getY(), im[i].getW(), im[i].getH());
        }

        if(im[i].getEmplacement() > 6 && im[i].getEmplacement() < 9)
        {
            im[i].draw(renderer, im[i].getX(), im[i].getY(), im[i].getW(), im[i].getH());
        }

        if(im[i].getEmplacement() == 9)
        {
            for(unsigned int f = 0; f < 3; f++){
                for(unsigned int k = 0; k < 2; k++)
                im[i].draw(renderer, im[i].getX()+k * 50, im[i].getY() + f * 70, im[i].getW(), im[i].getH());
            }            
        }
      
        if(im[i].getEmplacement() > 10 && im[i].getEmplacement() < 13 )
        {
            im[i].draw(renderer, im[i].getX(), im[i].getY(), im[i].getW(), im[i].getH());
        }

    }
    
    //newImage.draw(renderer,newImage.getX() ,newImage.getY(), newImage.getW(), newImage.getH());
    image0.draw(renderer,image0.getX() ,image0.getY(), image0.getW(), image0.getH());
    image1.draw(renderer,image1.getX() ,image1.getY(), image1.getW(), image1.getH());
    image2.draw(renderer,image2.getX() ,image2.getY(), image2.getW(), image2.getH());
    image3.draw(renderer,image3.getX() ,image3.getY(), image3.getW(), image3.getH());

    /************************************************************************************/

    font_im.setSurface(TTF_RenderText_Solid(font,"Welcome to Boorgir-Bar my fine sir !",font_color));
	font_im.loadFromCurrentSurface(renderer);
    // Ecrire un titre par dessus
    SDL_Rect positionTitre;
    positionTitre.x = 130;positionTitre.y = -5;positionTitre.w = 700;positionTitre.h = 70;
    SDL_RenderCopy(renderer,font_im.getTexture(),NULL,&positionTitre);

    /*ostringstream argent;
    int arg1 =0;
    for(int i =0; i<20; i++){
        arg1 = arg1 + i;
        argent << arg1;
        Argent.setSurface(TTF_RenderText_Solid(font, argent.str().c_str(), font_color));
        Argent.loadFromCurrentSurface(renderer);
    }*/
    //SDL_Rect

    /*Temps t;
    int timeRestant;
    do{
         timeRestant= jeu.getObj().getTemps().tempsRestant();
    //cout << "time left : " <<timeRestant<<endl;
    }while(jeu.getObj().getTemps().tempsRestant() < 0);

    //while(timeRestant !=0){
        ostringstream timeLeft;
        timeLeft << timeRestant;
        Time.setSurface(TTF_RenderText_Solid(font, timeLeft.str().c_str(), font_color));
        Time.loadFromCurrentSurface(renderer);
        SDL_Rect timePos;
        timePos.x = 400; timePos.y = 400;
        timePos.w = 50;
        timePos.h = 50;
        SDL_RenderCopy(renderer, Time.getTexture(), NULL, &timePos);
    
    
    */
        
    //}
    
    
    

    //Dessin des rectangles   
    for(unsigned int i=0; i<4; i++){
        SDL_Rect rect;
            if(i%2 == 0){
                rect.x = 409;
                rect.y = 725 + i*56;;
                rect.w = 141;
                rect.h = 102;
            }
            if(i%2!=0){
                rect.x = 560;
                rect.y = 725+(i-1)*56;
                rect.w = 141;
                rect.h = 102;
            }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect);
    }

    /*for(unsigned int i =0; i < 4; i++){
        SDL_Rect client;
        client.x = 100 + i * 200;
        client.y = 400;
        client.w = 150;
        client.h = 280;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &client);
    }

    for(unsigned int i =0; i < 4; i++){
        SDL_Rect commande;
        commande.x = 100 + i * 200;
        commande.y = 250;
        commande.w = 150;
        commande.h = 140;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &commande);
    }*/

    
    


    
}

void sdlJeu::mousePress(SDL_MouseButtonEvent& b){
    if(b.button == SDL_BUTTON_LEFT){
        //handle a left-click
        cout << b.x << " " << b.y << endl;
    }

    for(unsigned int i = 0; i < im.size(); i++){
        if(b.x > im[i].getX() && b.x < im[i].getX() + im[i].getW() && b.y > im[i].getY() && b.y < im[i].getY() + im[i].getH()){
                //if(im[i].getNom() != "Frites" && im[i].getNom() != "Jus" && im[i].getNom() != "Soda"){
                    setNewImg(im[i]);

                    if(image0.getNom()== "PainBSteakSaladeTomateKetchup"){
                            cout <<"wtf"<<endl;
                            //cout << "Wtf newima" << newImage
                            if(newImage.getNom() == "Ketchup"){
                                cout << "098743Can't add more sauce !" << endl;
                                newImage.setNom("Tomate");
                            }
                            
                        }
                //}
        }
    }

    /*if(b.x > 20  && b.x < 20 + 110 && b.y > 725 && b.y < 725 + 215){
        cout << "Je suis au block de " << im[2].getNom() << endl;
    }*/

   
    
    //cout << "over her newImage name is " << newImage.getNom() << endl;
    //cout << "over her imago0 name is " << image0.getNom() << endl;
    
    if(newImage.getNom() != "Frites" || newImage.getNom() != "Jus" || newImage.getNom() != "Soda" /*&& newImage.getNom() != "Mayo"*/)
    {
        //Table 0  
        if(mx > 411 && mx < 550 && my > 727 && my < 827){   
            string temp;
            temp = jeu.PreparerCommande(newImage.getNom(), 0);
            SDL_DestroyTexture(image0.getTexture());
            for(unsigned int i = 0; i < im.size(); i++){
                if(im[i].getNom() == temp){
                    //cout << "image0 " << image0.getNom() << "lol" << endl; 
                    setIm0(im[i]);
                    //cout << "image0 " << image0.getNom() << "lol" << endl; 
                    image0.setX(411 + ((130 - image0.getW()) / 2));
                    image0.setY(727 + ((100 - image0.getH()) / 2));
                    image0.setCase(0);
                    jeu.tabPrep[0] = temp;
                    cout << "tab 0 " << jeu.tabPrep[0]<< endl;
                }
            }
        }

        //Table 1
        if(mx > 560 && mx < 699 && my > 727 && my < 827){
            string temp;
            temp = jeu.PreparerCommande(newImage.getNom(), 1);
            SDL_DestroyTexture(image1.getTexture());
            newImage.setNom("");
            for(unsigned int i = 0; i < im.size(); i++){
                if(im[i].getNom() == temp){
                    setIm1(im[i]);
                    //cout << "image1 " << image1.getNom() << "lol" << endl; 
                    image1.setX(560 + ((130 - image1.getW()) / 2));
                    image1.setY(727 + ((100 - image1.getH()) / 2));
                    image1.setCase(1);
                    jeu.tabPrep[1] = temp;
                    cout << "tab 1 " << jeu.tabPrep[1] << endl;
                }
            }          
        }

        //Table 2
        if(mx > 411 && mx < 550 && my > 837 && my < 937){
            string temp;
            temp = jeu.PreparerCommande(newImage.getNom(), 2);
            SDL_DestroyTexture(image2.getTexture());
            newImage.setNom("");
            for(unsigned int i = 0; i < im.size(); i++){
                if(im[i].getNom() == temp){
                    setIm2(im[i]);
                    //cout << "image2 " << image2.getNom() << "lol" << endl; 
                    image2.setX(411 + ((130 - image2.getW()) / 2));
                    image2.setY(837 + ((100 - image2.getH()) / 2));
                    image2.setCase(2);
                    jeu.tabPrep[2] = temp;
                    cout << "tab 2 " << jeu.tabPrep[2]<< endl;
                }
            }          
        }

        //Table 3
        if(mx > 560 && mx < 699 && my > 837 && my < 937){
            string temp;
            temp = jeu.PreparerCommande(newImage.getNom(), 3);
            SDL_DestroyTexture(image3.getTexture());
            newImage.setNom("");
            for(unsigned int i = 0; i < im.size(); i++){
                if(im[i].getNom() == temp){
                    setIm3(im[i]);
                    //cout << "image3 " << image3.getNom() << "lol" << endl; 
                    image3.setX(560 + ((130 - image3.getW()) / 2));
                    image3.setY(837 + ((100 - image3.getH()) / 2));
                    image3.setCase(3);
                    jeu.tabPrep[3] = temp;
                    cout << "tab 3 " << jeu.tabPrep[3]<< endl;
                }
            }         
        }
    }
    image0.loadFromFile(image0.getChemin().c_str(), renderer);
    image1.loadFromFile(image1.getChemin().c_str(), renderer);
    image2.loadFromFile(image2.getChemin().c_str(), renderer);
    image3.loadFromFile(image3.getChemin().c_str(), renderer);
}

void sdlJeu::drawImgClient(){
    for(unsigned int i = 0; i <im.size(); i++){
        if(im[i].getEmplacement() > 19 && im[i].getEmplacement() < 24)
            im[i].draw(renderer, im[i].getX(), im[i].getY(), im[i].getW(), im[i].getH());

        if(im[i].getEmplacement() > 23 && im[i].getEmplacement() < 28)
            im[i].draw(renderer, im[i].getX(), im[i].getY(), im[i].getW(), im[i].getH());
    }


}

void sdlJeu::chargeInfoClient(){
    //jeu.chargerCarte("./txt/Carte.txt");
    //jeu.creationClient(4);
    for(unsigned int i = 0; i < jeu.getTabClient().size(); i++){
        for(unsigned int j = 0; j < jeu.getTabClient()[i].getCom().size(); j++){
            cout << endl<<"Le client " << i << " a commande " << jeu.getTabClient()[i].getCom()[j].getNom() << endl;
            for(unsigned int k = 0; k< im.size(); k++){
                if(jeu.getTabClient()[i].getCom()[j].getNom() == im[k].getNom())
                {
                    if(i == 0)
                        imCom0.push_back(im[k]);
                    
                    if(i == 1)
                        imCom1.push_back(im[k]);
                    

                    if(i == 2)
                        imCom2.push_back(im[k]);
                    
                    if(i == 3)
                        imCom3.push_back(im[k]);
                    
                }
            }
        }
    }

}

void sdlJeu::loadImgCommande(){
    for(unsigned int i =0; i < imCom0.size(); i++){
        imCom0[i].loadFromFile(imCom0[i].getChemin().c_str(), renderer);
    }

    for(unsigned int i =0; i < imCom1.size(); i++){
        imCom1[i].loadFromFile(imCom1[i].getChemin().c_str(), renderer);
    }
    
    for(unsigned int i =0; i < imCom2.size(); i++){
        imCom2[i].loadFromFile(imCom2[i].getChemin().c_str(), renderer);
    }
    
    for(unsigned int i =0; i < imCom3.size(); i++){
        imCom3[i].loadFromFile(imCom3[i].getChemin().c_str(), renderer);
    }
}

void sdlJeu::drawImgCommande(){
    for(unsigned int i =0; i < imCom0.size(); i++){
        unsigned int x = 85 + ((im[30].getW() - imCom0[i].getW())/2);
        unsigned int y = im[30].getY() + ((im[30].getH() - imCom0[i].getH())/2);
        unsigned int w = imCom0[i].getW() - (imCom0[i].getW()*0.3);
        unsigned int h = imCom0[i].getH() - (imCom0[i].getH()*0.3);
        imCom0[i].draw(renderer,  x + i * 35 , y, w,  h);
    }

    for(unsigned int i =0; i < imCom1.size(); i++){
        unsigned int x = 290 + ((im[30].getW() - imCom1[i].getW())/2);
        unsigned int y = im[30].getY() + ((im[30].getH() - imCom1[i].getH())/2);
        unsigned int w = imCom1[i].getW() - (imCom1[i].getW()*0.3);
        unsigned int h = imCom1[i].getH() - (imCom1[i].getH()*0.3);
        imCom1[i].draw(renderer,  x + i * 35 , y, w,  h);
    }
    
    for(unsigned int i =0; i < imCom2.size(); i++){
        unsigned int x = 490 + ((im[30].getW() - imCom2[i].getW())/2);
        unsigned int y = im[30].getY() + ((im[30].getH() - imCom2[i].getH())/2);
        unsigned int w = imCom2[i].getW() - (imCom2[i].getW()*0.3);
        unsigned int h = imCom2[i].getH() - (imCom2[i].getH()*0.3);
        imCom2[i].draw(renderer,  x + i * 35 , y, w,  h);
    }
    
    for(unsigned int i =0; i < imCom3.size(); i++){
        unsigned int x = 690 + ((im[30].getW() - imCom3[i].getW())/2);
        unsigned int y = im[30].getY() + ((im[30].getH() - imCom3[i].getH())/2);
        unsigned int w = imCom3[i].getW() - (imCom3[i].getW()*0.3);
        unsigned int h = imCom3[i].getH() - (imCom3[i].getH()*0.3);
       imCom3[i].draw(renderer,  x + i * 35 , y, w,  h);
    }
}

void sdlJeu::servirClient(){
  
    //Bubble 0
    if(mx > 110 && mx < 240 && my > 270 && my < 400){
        //cout << "hola" <<endl;
    }

    for(unsigned int i =0; i<imCom0.size(); i++){
        //Table 0
        if(mx > 411 && mx < 550 && my > 727 && my < 827){
            //cout << "im0" << image0.getNom() << endl;
            if(image0.getNom() == imCom0[i].getNom()){
                aServir = image0.getNom();
                cout << "Client 0 veut recette de Tab 0" << endl;
                unsigned int f = 0;
                servirClientI(f);

            }
            
            if(image0.getNom() == imCom1[i].getNom()){
                aServir = image0.getNom();
                cout << "Client 1 veut recette de Tab 0" << endl;
            }
        
            
            if(image0.getNom() == imCom2[i].getNom()){
                aServir = image0.getNom();
                cout << "Client 2 veut recette de Tab 0" << endl;
            }

            if(image0.getNom() == imCom3[i].getNom()){
                aServir = image0.getNom();
                cout << "Client 3 veut recette de Tab 0 " << endl;
            }
        }
        //Table 1
        if(mx > 560 && mx < 699 && my > 727 && my < 827){
            cout << "im1" << image1.getNom() << endl;
            if(image1.getNom() == imCom0[i].getNom()){
                aServir = image1.getNom();
                cout << "Client 0 veut recette de Tab 1 " << endl;
            }
            
            if(image1.getNom() == imCom1[i].getNom()){
                aServir = image1.getNom();
                cout << "Client 1 veut recette de Tab 1" << endl;
            }
        
            
            if(image1.getNom() == imCom2[i].getNom()){
                aServir = image1.getNom();
                cout << "Client 2 veut recette de Tab 1 " << endl;
            }

            if(image1.getNom() == imCom3[i].getNom()){
                aServir = image1.getNom();
                cout << "Client 3 veut recette de Tab 1" << endl;
            }
        }
        //Table 2
        if(mx > 411 && mx < 550 && my > 837 && my < 937){
            cout << "im2" << image2.getNom() << endl;
            if(image2.getNom() == imCom0[i].getNom()){
                aServir = image2.getNom();
                cout << "Client 0 veut recette de Tab 2" << endl;
            }
            
            if(image2.getNom() == imCom1[i].getNom()){
                aServir = image2.getNom();
                cout << "Client 1 veut recette de Tab 2" << endl;
            }
        
            
            if(image2.getNom() == imCom2[i].getNom()){
                aServir = image2.getNom();
                cout << "Client 2 veut recette de Tab 2 " << endl;
            }

            if(image2.getNom() == imCom3[i].getNom()){
                aServir = image2.getNom();
                cout << "Client 3 veut recette de Tab 2" << endl;
            }
        }
        
        //Table 3
        if(mx > 560 && mx < 699 && my > 837 && my < 937){
            cout << "im3" << image3.getNom() << endl;
            if(image3.getNom() == imCom0[i].getNom()){
                aServir = image3.getNom();
                cout << "Client 0 veut recette de Tab 3 " << endl;
            }
            
            if(image3.getNom() == imCom1[i].getNom()){
                aServir = image3.getNom();
                cout << "Client 1 veut recette de Tab 3" << endl;
            }
        
            
            if(image3.getNom() == imCom2[i].getNom()){
                aServir = image3.getNom();
                cout << "Client 2 veut recette de Tab 3 " << endl;
            }

            if(image3.getNom() == imCom3[i].getNom()){
                aServir = image3.getNom();
                cout << "Client 3 veut recette de Tab 3 " << endl;
            }
        }
    }

    

    /*for(unsigned int i=0; i<jeu.getTabClient().size(); i++){
        for(unsigned int j=0; j < jeu.getTabClient()[i].getCom().size(); j++){
            cout << "AaAA" << jeu.getTabClient()[i].getCom()[j].getNom() << endl;
        }
       
    }

    for(unsigned int i = 0; i< 4; i++){
        cout <<"qfzsrez" << jeu.tabPrep[i] << endl;
    }*/
}


void sdlJeu::servirClientI(unsigned int &i){

    //Servir Client 0
    if(i==0){
         if(mx > 95 && mx < 250 && my > 400 && my < 681){
            for(unsigned int i = 0; i < imCom0.size(); i++){
                if(aServir == imCom0[i].getNom()){
                    cout<< "On efface la com du client 0" << aServir << endl;
                    unsigned int idCl =0;
                    jeu.effaceRecette(idCl, i);
                }

            }
        }
    }


    if(i==1){
         //Servir Client 1
        if(mx > 300 && mx < 455 && my > 400 && my < 681){
            for(unsigned int i = 0; i < imCom1.size(); i++){
                if(aServir == imCom1[i].getNom()){
                    cout<< "On efface la com du client 1" << aServir << endl;
                    unsigned int idCl =0;
                    jeu.effaceRecette(idCl, i);
                }

            }
        }
    }


    if(i==2){
        
        if(mx > 500 && mx < 555 && my > 400 && my < 681){
            for(unsigned int i = 0; i < imCom2.size(); i++){
                if(aServir == imCom2[i].getNom()){
                    cout<< "On efface la com du client 2" << aServir << endl;
                    unsigned int idCl =0;
                    jeu.effaceRecette(idCl, i);
                }

            }
        }
    }

    if(i==3){
         //Servir Client 3
        if(mx > 700 && mx < 855 && my > 400 && my < 681){
            for(unsigned int i = 0; i < imCom3.size(); i++){
                if(aServir == imCom3[i].getNom()){
                    cout<< "On efface la com du client 3" << aServir << endl;
                    cout << jeu.getTabClient()[3].getCom()[0].getNom()<<endl;
                    cout << jeu.tabPrep[i] << "fgvdhr"<<endl;
                    unsigned int idCl =3;
                    jeu.effaceRecette(idCl, i);
                    cout << "done: deleting client 3 com" << endl;
                    
                }
                //cout << "im com3" << imCom3[i].getNom();
            }
        }
    }
   
    
    
}




void sdlJeu::sdlBoucle () {
    SDL_Event events;
	bool quit = false;
    jeu.getObj().choixNiveau(1);
    chargeInfoClient();
    /*for(unsigned int i = 0; i < imCom0.size(); i++){
            //cout << " 0for image " << i << " we have " << imCom0[i].getNom() << endl;
            cout << "Nom : "<<  " "<< imCom0[i].getNom() <<
            " | Emplacement " << " "<< imCom0[i].getEmplacement() << 
            " | Chemin : " << " "<< imCom0[i].getChemin() <<
            " | X : " << " "<< imCom0[i].getX() << 
            " | Y : " << " "<< imCom0[i].getY() << 
            " | W : " << " "<< imCom0[i].getW() << 
            " | H : " << " "<< imCom0[i].getH() <<
            endl;

        }
        cout << endl;
        for(unsigned int i = 0; i < imCom1.size(); i++){
            cout << " 1for image " << i << " we have " << imCom1[i].getNom() << endl;
        }
        cout << endl;
        for(unsigned int i = 0; i < imCom2.size(); i++){
            cout << " 2for image " << i << " we have " << imCom2[i].getNom() << endl;
        }
        cout << endl;
        for(unsigned int i = 0; i < imCom3.size(); i++){
            cout << " 3for image " << i << " we have " << imCom3[i].getNom() << endl;
        }*/

    // tant que ce n'est pas la fin ...
	while (!quit) {
        SDL_GetMouseState(&mx, &my);

       
		// tant qu'il y a des evenements ï¿½ traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) quit = true;       // Si l'utilisateur a clique sur la croix de fermeture
                else if (events.type == SDL_KEYDOWN) {       // Si une touche est enfoncee
                        //bool mangePastille = false;
                        switch (events.key.keysym.scancode) {
                        case SDL_SCANCODE_UP:
                            //mangePastille = jeu.actionClavier('b');    // car Y inverse
                            break;
                        case SDL_SCANCODE_DOWN:
                            //mangePastille = jeu.actionClavier('h');     // car Y inverse
                            break;
                        case SDL_SCANCODE_LEFT:
                            //mangePastille = jeu.actionClavier('g');
                            break;
                        case SDL_SCANCODE_RIGHT:
                            //mangePastille = jeu.actionClavier('d');
                            break;
                        case SDL_SCANCODE_ESCAPE:
                        case SDL_SCANCODE_Q:
                            quit = true;
                            break;
                        default: break;
                        }
                        /*if ((withSound) && (mangePastille))
                            Mix_PlayChannel(-1,sound,0);*/
			        }
                    if(events.type == SDL_MOUSEBUTTONDOWN){
                        if(events.button.button == SDL_BUTTON_LEFT){
                            mousePress(events.button);
                            //servirClient();
                        }
                        if(events.button.button == SDL_BUTTON_RIGHT){
                            servirClient();
                            if(mx > 0 && mx < 50 && my > 0 && my < 50){
                                
                                for(unsigned int i = 0; i < jeu.getTabClient().size(); i++){
                                    cout << "bbvv" << endl;
                                    for(unsigned int j = 0; j < jeu.getTabClient()[i].getCom().size(); j++){
                                        cout << endl<<"Le client " << i << " a commande " << jeu.getTabClient()[i].getCom()[j].getNom() << endl;

                                    }



                                }
                            }         
                        }
                   
		            }
         // on affiche le jeu sur le buffer cachï¿½
        sdlAff();

        drawImgClient();
        drawImgCommande();

		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}
    /*SDL_DestroyTexture(background.getTexture());
    for(unsigned int i =0; i<im.size(); i++){
        SDL_DestroyTexture(im[i].getTexture());
    }
    
    SDL_DestroyTexture(image0.getTexture());
    SDL_DestroyTexture(image1.getTexture());
    SDL_DestroyTexture(image2.getTexture());
    SDL_DestroyTexture(image3.getTexture());*/

}
}