#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include "sdlImage.h"
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;


float temps () {
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS SDLJEU =============== //
sdlJeu::sdlJeu () : jeu() {
    /**********************Nombre d'ingredient ajoute par le joueur*************/
    nbrIngJ = 11;
    newImage.setChemin("img/PainHD.png");
    image0.setChemin(newImage.getChemin());
    image1.setChemin(newImage.getChemin());
    image2.setChemin(newImage.getChemin());
    image3.setChemin(newImage.getChemin());
    image0.setNom("Undefined");
    image1.setNom("Undefined");
    image2.setNom("Undefined");
    image3.setNom("Undefined");


    /*******************Appelle a la classe de chargement des images*****************************/
    loadImg.chargerTxtImages("./txt/testSDL.txt");
    jeu.chargerRecette(jeu.getTabRec(),"./txt/test.txt");
    
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

    /*im_pacman.loadFromFile("data/pacman.png",renderer);
    im_mur.loadFromFile("data/mur.png",renderer);
    im_pastille.loadFromFile("data/pastille.png",renderer);
    im_fantome.loadFromFile("data/fantome.png",renderer);*/

    //Boucle qui permet de charger toutes les images grace au chemin stocker au tab dynamique
    /*for(unsigned int i = 0; i < loaded_im.size(); i++){
        loaded_im[i].loadFromFile(loaded_im[i].getChemin().c_str(), renderer);
    }*/

    //Image i;
    //i.chargerImage(loaded_im, "./txt/testSDL.txt");

    /*for(unsigned int i =0; i<loaded_im.size(); i++){
        cout << "Le nom est : " << loaded_im[i].getNom() << endl << " Le chemin est : " << loaded_im[i].getChemin() << endl << endl;
        loaded_im[i].loadFromFile(loaded_im[i].getChemin().c_str(), renderer);
    }*/

    sdlLoadImgFile();

    //newImage.loadFromFile("img/Tomate.png", renderer);
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

	font_im.setSurface(TTF_RenderText_Solid(font,"Welcome to Boorgir-Bar my fine sir !",font_color));
	font_im.loadFromCurrentSurface(renderer);

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

void sdlJeu::sdlLoadImgFile(){

    //Charger le background
    background.loadFromFile("./img/Backgr.png", renderer);

    for(unsigned int i =0; i< im.size(); i++){
        im[i].loadFromFile(im[i].getChemin().c_str(), renderer);
    }

    image0.loadFromFile(image0.getChemin().c_str(), renderer);
    image1.loadFromFile(image1.getChemin().c_str(), renderer);
    image2.loadFromFile(image2.getChemin().c_str(), renderer);
    image3.loadFromFile(image3.getChemin().c_str(), renderer);
}

unsigned int sdlJeu::getNbrIngJ() const{
    //cout << "inside getnbr we have nbr = to " << im.size() << endl;
    return im.size() - nbrIngJ;
}

/*void sdlJeu::setNewImg(const string & nIm, const unsigned int & eIm, const string & cIm, const unsigned int & xIm, const unsigned int & yIm, const unsigned int & wIm, const unsigned int & hIm){
    newImage.setNom(nIm);
    newImage.setEmplacement(100);
    newImage.setChemin(cIm);
    newImage.setW(wIm);
    newImage.setH(hIm);
}*/

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
      
        if(im[i].getEmplacement() == 11 || im[i].getEmplacement() == 12 )
        {
            im[i].draw(renderer, im[i].getX(), im[i].getY(), im[i].getW(), im[i].getH());
        }
    }
    
    //newImage.draw(renderer,newImage.getX() ,newImage.getY(), newImage.getW(), newImage.getH());
     //cout << "44444444im0 chem" << image0.getChemin() << endl;

    image0.draw(renderer,image0.getX() ,image0.getY(), image0.getW(), image0.getH());
    image1.draw(renderer,image1.getX() ,image1.getY(), image1.getW(), image1.getH());
    image2.draw(renderer,image2.getX() ,image2.getY(), image2.getW(), image2.getH());
    image3.draw(renderer,image3.getX() ,image3.getY(), image3.getW(), image3.getH());

    /************************************************************************************/

    // Ecrire un titre par dessus
    SDL_Rect positionTitre;
    positionTitre.x = 130;positionTitre.y = -5;positionTitre.w = 700;positionTitre.h = 70;
    SDL_RenderCopy(renderer,font_im.getTexture(),NULL,&positionTitre);

    //Dessin des rectangles
    SDL_Rect rect;
    rect.x = 20;
    rect.y = 725;
    rect.w = 110;
    rect.h = 215;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);

    for(unsigned int i=0; i<6; i++){
        SDL_Rect rect2;
            if(i%2 == 0){
                rect2.x = 210;
                rect2.y = 737 + i * 33;
                rect2.w = 70;
                rect2.h = 56;
            }
            if(i%2!=0){
                rect2.x = 290;
                rect2.y = 737 +(i-1)*33;
                rect2.w = 70;
                rect2.h = 56;
            }
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &rect2);
    }
   
    for(unsigned int i=0; i<4; i++){
        SDL_Rect rect3;
            if(i%2 == 0){
                rect3.x = 409;
                rect3.y = 725;
                rect3.w = 141;
                rect3.h = 102;
            }
            if(i%2!=0){
                rect3.x = 560;
                rect3.y = 725+(i-1)*56;
                rect3.w = 141;
                rect3.h = 102;
            }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect3);
    }

    
}

void sdlJeu::mousePress(SDL_MouseButtonEvent& b){
    if(b.button == SDL_BUTTON_LEFT){
        //handle a left-click
        //cout << b.x << " " << b.y << endl;
    }

    for(unsigned int i = 0; i < im.size(); i++){
        if(b.x > im[i].getX() && b.x < im[i].getX() + im[i].getW() && b.y > im[i].getY() && b.y < im[i].getY() + im[i].getH()){
                if(im[i].getNom() != "Frites" && im[i].getNom() != "Jus" && im[i].getNom() != "Soda")
                    setNewImg(im[i]);
        }
    }

    /*if(b.x > 20  && b.x < 20 + 110 && b.y > 725 && b.y < 725 + 215){
        cout << "Je suis au block de " << im[2].getNom() << endl;
    }*/

     //Case0
    if(mx > 411 && mx < 550 && my > 727 && my < 827){
       if(image0.getNom() != "Frites" && image0.getNom() != "Jus" && image0.getNom() != "Soda")
        {
            string temp;
            temp = jeu.PreparerCommande(newImage.getNom(), 0);
            newImage.setNom("");
            for(unsigned int i = 0; i < im.size(); i++){
                if(im[i].getNom() == temp){
                    setIm0(im[i]);
                    image0.setX(411 + ((130 - image0.getW()) / 2));
                    image0.setY(727 + ((100 - image0.getH()) / 2));
                    image0.setCase(0);
                }
            }
        }
    }

    //Case1
    if(mx > 560 && mx < 699 && my > 727 && my < 827){
       if(image1.getNom() != "Frites" && image1.getNom() != "Jus" && image1.getNom() != "Soda")
        {
            string temp;
            temp = jeu.PreparerCommande(newImage.getNom(), 1);
            newImage.setNom("");
            for(unsigned int i = 0; i < im.size(); i++){
                if(im[i].getNom() == temp){
                    setIm1(im[i]);
                    image1.setX(560 + ((130 - image1.getW()) / 2));
                    image1.setY(727 + ((100 - image1.getH()) / 2));
                    image1.setCase(1);
                }
            }
        }            
    }

    //Case2
    if(mx > 411 && mx < 550 && my > 837 && my < 937){
       if(image2.getNom() != "Frites" && image2.getNom() != "Jus" && image2.getNom() != "Soda")
        {
            string temp;
            temp = jeu.PreparerCommande(newImage.getNom(), 2);
            newImage.setNom("");
            for(unsigned int i = 0; i < im.size(); i++){
                if(im[i].getNom() == temp){
                    setIm2(im[i]);
                    image2.setX(411 + ((130 - image2.getW()) / 2));
                    image2.setY(837 + ((100 - image2.getH()) / 2));
                    image2.setCase(2);
                }
            }
        }            
    }

    //Case3
    if(mx > 560 && mx < 699 && my > 837 && my < 937){
       if(image3.getNom() != "Frites" && image3.getNom() != "Jus" && image3.getNom() != "Soda")
        {
            string temp;
            temp = jeu.PreparerCommande(newImage.getNom(), 3);
            newImage.setNom("");
            for(unsigned int i = 0; i < im.size(); i++){
                if(im[i].getNom() == temp){
                    setIm3(im[i]);
                    image3.setX(560 + ((130 - image3.getW()) / 2));
                    image3.setY(837 + ((100 - image3.getH()) / 2));
                    image3.setCase(3);
                }
            }
        }            
    }
   image0.loadFromFile(image0.getChemin().c_str(), renderer);
   image1.loadFromFile(image1.getChemin().c_str(), renderer);
   image2.loadFromFile(image2.getChemin().c_str(), renderer);
   image3.loadFromFile(image3.getChemin().c_str(), renderer);
}

void sdlJeu::sdlBoucle () {
    SDL_Event events;
	bool quit = false;

    // tant que ce n'est pas la fin ...
	while (!quit) {
        SDL_GetMouseState(&mx, &my);

        // on affiche le jeu sur le buffer cachï¿½
        sdlAff();

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
                        mousePress(events.button);
                    }
		}
		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}
}