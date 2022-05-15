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

        bool souris;
        bool touche;

        Image background;

        unsigned int nbrIngJ;

        vector<Image> im;

        loadImage loadImg;

        Image newImage;
        Image image0, image1, image2, image3;
        int mx, my; 

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

        //void setNewImg(const string & nIm, const unsigned int & eIm, const string & cIm, const unsigned int & xIm, const unsigned int & yIm, const unsigned int & wIm, const unsigned int & hIm);

        void setNewImg(Image i);


        void setIm0(Image i0);

        void setIm1(Image i1);

        void setIm2(Image i2);

        void setIm3(Image i3);

        void mousePress(SDL_MouseButtonEvent& b);
};

#endif