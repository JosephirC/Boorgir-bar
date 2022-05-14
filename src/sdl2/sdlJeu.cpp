#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include "sdlImage.h"
#include <stdlib.h>
//#ifdef _WIN32
//#include <windows.h>
//#else
//#endif // WIN32
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;


float temps () {
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS SDLJEU =============== //

sdlJeu::sdlJeu () : jeu() {
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
	dimy = 960 +  0 *4;

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

    /**********************Nombre d'ingredient ajoute par le joueur*************/
    nbrIngJ = im.size() - 11;
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

void sdlJeu::sdlLoadImage(){

    //Charger le background
    background.loadFromFile("./img/Backgr.png", renderer);

     
    //Charger les textures grace au fichier txt
   chargerTxtImages(im, "./txt/testSDL.txt");
    cout << "22"<<endl;
    for(unsigned int i =0; i< im.size(); i++){
        cout << "Chemin : " << im[i].getChemin() << endl;
        im[i].loadFromFile(im[i].getChemin().c_str(), renderer);
    }
}

/*vector<Image> sdlJeu::getImageVec() const{
    return im;
}*/

void sdlJeu::chargerTxtImages(vector<Image> & vecIm, const string & filenameIm){
    ifstream fileIm(filenameIm.c_str());
    string nom, chemin;
    unsigned int emplacement, x , y, w, h;

    if(fileIm.is_open()){
        while(fileIm >> nom >> emplacement >>  chemin >> x >> y >> w >> h){
            cout <<"in" <<endl;
            Image ima(nom, emplacement, chemin, x , y, w, h);
            vecIm.push_back(ima);
        }

        fileIm.close();
    }
    
    else
        cout << "Failed to open file..." << endl;
}

unsigned int sdlJeu::getNbrIngJ() const{
    return nbrIngJ;
}


void sdlJeu::sdlAff () {
	//Remplir l'�cran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

	int x,y;
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

    /************************************************************************************/

  

    
    

    //SDL_RenderCopy(renderer,font_im.getTexture(),NULL,&positionTitre);







    //Salade.loadFromFile("./img/Salade.png", renderer);
    //Salade.draw(renderer, 100, 100 ,120, 120);
    //SDL_RenderCopy(renderer, Salade.getTexture(), NULL, &positionSalade);

    /*vector<Image> ima;
    Image i;
    i.chargerImage(ima, "./txt/testSDL.txt");
    for(unsigned int i =0; i<ima.size(); i++){
        int x = 0;
        int y = 0; 
        int w = 100;
        int h = 100;
        Image im;
        im.loadFromFile(ima[i].getChemin().c_str(), renderer);
        im.draw(renderer, x + i * 10, y ,w, h);
    }*/


    /*SDL_Rect positionSalade;
    positionSalade.x = 200;
    positionSalade.y = 300;
    positionSalade.w = 150;
    positionSalade.h = 150;

    SDL_Rect positionTomate;
    positionTomate.x = 300;
    positionTomate.y = 300;
    positionTomate.w = 50;
    positionTomate.h = 50;


    SDL_Rect positionPainHD;
    positionPainHD.x = 200;
    positionPainHD.y = 200;
    positionPainHD.w = 50;
    positionPainHD.h = 50;

    SDL_Rect positionSaucisse;
    positionSaucisse.x = 300;
    positionSaucisse.y = 200;
    positionSaucisse.w = 50;
    positionSaucisse.h = 50;

    SDL_Rect positionPainB;
    positionPainB.x = 200;
    positionPainB.y = 100;
    positionPainB.w = 50;
    positionPainB.h = 50;

    SDL_Rect positionSteak;
    positionSteak.x = 300;
    positionSteak.y = 100;
    positionSteak.w = 50;
    positionSteak.h = 50;*/


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
      
        if(im[i].getEmplacement() > 10)
        {
            im[i].draw(renderer, im[i].getX(), im[i].getY(), 100,100 );
        }

        
    }

      // Ecrire un titre par dessus
    SDL_Rect positionTitre;
    positionTitre.x = 130;positionTitre.y = -5;positionTitre.w = 700;positionTitre.h = 70;
    SDL_RenderCopy(renderer,font_im.getTexture(),NULL,&positionTitre);



    /*for(unsigned int i = 0; i < loaded_im.size(); i++){

    }*/




    SDL_Rect rect;
    rect.x = 280;
    rect.y = 635;
    rect.w = 100;
    rect.h = 100;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderPresent(renderer);



    /*******************************************/

    SDL_Event event;
    SDL_Point mousePosition;

    SDL_Rect salade;
    salade.x = 200;
    salade.y = 630;
    salade.w = 100;
    salade.h = 100;

    // Mouse click coords from event handler
    mousePosition.x = event.motion.x; 
    mousePosition.y = event.motion.y;

    if (SDL_PointInRect(&mousePosition, &salade)) {
        // Do something
        cout << "Aaaaaaaaaa" <<endl;
        }
    


    

}

void sdlJeu::mousePress(SDL_MouseButtonEvent& b){
    if(b.button == SDL_BUTTON_LEFT){
        //handle a left-click
        cout << b.x << " " << b.y << endl;
    }
    for(unsigned int i = 0; i < im.size(); i++){
        if(b.x > im[i].getX() && b.x < im[i].getX() + im[i].getW() && b.y > im[i].getY() && b.y < im[i].getY() + im[i].getH()){
            cout << "Je suis a l'image " << im[i].getNom() << " lol" << endl;
        }
    }

}

void sdlJeu::sdlBoucle () {
    SDL_Event events;
	bool quit = false;

    sdlLoadImage();

    	// tant que ce n'est pas la fin ...
	while (!quit) {
        
		// tant qu'il y a des evenements � traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) quit = true;       // Si l'utilisateur a clique sur la croix de fermeture
                else 
                    if (events.type == SDL_KEYDOWN) {       // Si une touche est enfoncee
                       
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
                        break;

                    }

		}

		// on affiche le jeu sur le buffer cach�
		sdlAff();

		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}
}

