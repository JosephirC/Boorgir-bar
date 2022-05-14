#ifndef _SDL_JEU_H
#define _SDL_JEU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <vector>
#include "../Jeu.h"
#include "sdlImage.h"
#include "sdlLoadImage.h"

class sdlJeu {

    private : 

        Jeu jeu;

        SDL_Window * window;
        SDL_Renderer * renderer;

        TTF_Font * font;
        Image font_im;
        SDL_Color font_color;

        Mix_Chunk * sound;
        bool withSound;

        //vector<Image> loaded_im;

        bool souris;
        bool touche;

        Image background;

        unsigned int nbrIngJ;

        vector<Image> im;

        loadImage loadImg;

        //vector<Image> newImage;
        Image newImage;

        bool isClicked = true;


        

    public :

        sdlJeu ();
        ~sdlJeu ();
        void sdlBoucle ();
        void sdlAff ();
        
        void sdlLoadImgFile();

       // void MenuPrincipal(Jeu & Game);
       // bool afficherAccueil();
       // void AttendreClic(int & x, int & y);
       // void RenduImage (SDL_Renderer * renderer, char* nomImage, int x, int y, double angle, SDL_RendererFlip flip);

        //vector<Image> getImageVec() const;

        void setImageVector(vector<Image> vI);

        unsigned int getNbrIngJ() const;

        void mousePress(SDL_MouseButtonEvent& b);
  

        

};

#endif