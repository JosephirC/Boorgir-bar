#ifndef _SDL_H
#define _SDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

using namespace  std;

class AffichageSDL{

    private :

        unsigned int dimx, dimy;

    public :

        SDL_Rect zoom;
        SDL_Window *window;
        SDL_Renderer *renderer;

        void afficher();

        void afficher_init();

        void afficher_boucle();

};

#endif