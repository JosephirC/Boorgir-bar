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

unsigned int sdlJeu::getNbrIngJ() const{
    cout << "inside getnbr we have nbr = to " << im.size() << endl;
    return im.size() - nbrIngJ;
}

sdlJeu::sdlJeu () : jeu() {
    /**********************Nombre d'ingredient ajoute par le joueur*************/
    nbrIngJ = 11;

    /*******************Appelle a la classe de chargement des images*****************************/
    loadImg.chargerTxtImages("./txt/testSDL.txt");
    
    //Copiage de notre tab dynamique dans le tab dynamique de sdlJeu
    for(unsigned int i =0; i < loadImg.getLoadedImage().size(); i++){
        im.push_back(loadImg.getLoadedImage()[i]); 
    }
    cout << endl << endl << "aa" << im.size() << endl; 

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

    cout << "nbr ing apres dimy = " << getNbrIngJ() << endl;

    cout << "dimy " << dimy << endl;
    cout << "nbrIng " << getNbrIngJ() << endl;

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

   newImage.loadFromFile("./img/Tomate.png", renderer);
}

/*vector<Image> sdlJeu::getImageVec() const{
    return im;
}*/

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
            im[i].draw(renderer, im[i].getX(), im[i].getY(), im[i].getW(), im[i].getH());
        }
    }

      // Ecrire un titre par dessus
    SDL_Rect positionTitre;
    positionTitre.x = 130;positionTitre.y = -5;positionTitre.w = 700;positionTitre.h = 70;
    SDL_RenderCopy(renderer,font_im.getTexture(),NULL,&positionTitre);



    /*for(unsigned int i = 0; i < loaded_im.size(); i++){

    }*/


    SDL_Rect rect;
    rect.x = 20;
    rect.y = 725;
    rect.w = 110;
    rect.h = 215;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);
    //SDL_RenderPresent(renderer);

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
        //SDL_RenderPresent(renderer);
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

        //SDL_RenderPresent(renderer);
    }

    
}

void sdlJeu::mousePress(SDL_MouseButtonEvent& b){
    string nameClick;
    unsigned int img;
    if(b.button == SDL_BUTTON_LEFT){
        //handle a left-click
        cout << b.x << " " << b.y << endl;
    }
    for(unsigned int i = 0; i < im.size(); i++){
        if(b.x > im[i].getX() && b.x < im[i].getX() + im[i].getW() && b.y > im[i].getY() && b.y < im[i].getY() + im[i].getH()){
            cout << "Je suis a l'image " << im[i].getNom() << " lol de coords " << b.x << " " << b.y << endl;
            nameClick = im[i].getNom();
            img = i;
        }
    }
    if(b.x > 20  && b.x < 20 + 110 && b.y > 725 && b.y < 725 + 215){
        cout << "Je suis au block de " << im[2].getNom() << endl;
    }

    //Case1
    /*if(b.x > 411 && b.x < 550 && b.y > 727 && b.y < 827){
        //Image newImage(im[1].getNom(), im[1].getEmplacement(), im[1].getChemin(), im[1].getX(), im[1].getY(), im[1].getW(), im[1].getH());
       // newImage.loadFromFile( newImage.getChemin().c_str(), renderer);
        //newImage.draw(renderer, 476, 777, newImage.getW(), newImage.getH());

        //cout << "new Image chemin : " <<  newImage.getChemin() << endl;

        /*Image Tomate("tomtes", 50, "srig", 476, 477, 40, 40);
        Tomate.loadFromFile("./img/Tomate.png", renderer);
        Tomate.draw(renderer, Tomate.getX(), Tomate.getY(), Tomate.getW(), Tomate.getH());
        SDL_RenderPresent(renderer);*/


       /* newImage.draw(renderer, 100, 100, 50, 50);

    }*/

}

void sdlJeu::sdlBoucle () {
    SDL_Event events;
	bool quit = false;
    int mx, my;
    // tant que ce n'est pas la fin ...
	while (!quit) {
        SDL_GetMouseState(&mx, &my);

        // on affiche le jeu sur le buffer cach�
        sdlAff();
        
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

                        //Case1
                        if(mx > 411 && mx < 550 && my > 727 && my < 827 && isClicked == true){

                            //Image newImage(im[1].getNom(), im[1].getEmplacement(), im[1].getChemin(), im[1].getX(), im[1].getY(), im[1].getW(), im[1].getH());
                        // newImage.loadFromFile( newImage.getChemin().c_str(), renderer);
                            //newImage.draw(renderer, 476, 777, newImage.getW(), newImage.getH());

                            //cout << "new Image chemin : " <<  newImage.getChemin() << endl;

                            /*Image Tomate("tomtes", 50, "srig", 476, 477, 40, 40);
                            Tomate.loadFromFile("./img/Tomate.png", renderer);
                            Tomate.draw(renderer, Tomate.getX(), Tomate.getY(), Tomate.getW(), Tomate.getH());
                            */
                           newImage.setX( mx);
                           newImage.setY( my);
                           newImage.setW(100);
                           newImage.setH(100);
                           im.push_back(newImage);
                           //newImage.draw(renderer, 100, 100, 50, 50);
                            isClicked = false;
                            

                            
                        }

                        

                    }

		}

		
		

		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}
}

