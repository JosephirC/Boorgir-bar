#ifndef _SDL_JEU_H
#define _SDL_JEU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "Jeu.h"


class Image{

    private :

        SDL_Surface * surface;
        SDL_Texture * texture;
        bool has_changed;
        string nom;
        string chemin;
        int dimx, dimy;

    public : 

        Image();

        Image(const string & nomIm, const string & cheminIm);

        void loadFromFile(const char * filename, SDL_Renderer * renderer);

        void loadFromCurrentSurface(SDL_Renderer * renderer);

        void draw(SDL_Renderer * renderer, int x, int y, int w = -1, int h = -1);

        SDL_Textutre * getTexture() const;

        void chargerImage(vector<Image> & vecIm, const string & filenameIm); // cherger image dans un tableau dynamique;

        void setSurface(SDL_Surface * surf);

        void setNom(const string & nomIm); // peut etre inutile

        void setChemin(const string & cheminIm); // peut etre inutile

        void setDimX(const int & x);

        void setDimY(const int & y);

        string getNom() const;

        string getChemin() const;

        int getDimX() const;

        int getDimY() const;
};


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

        vector<Image> loaded_im;

        bool souris;
        bool touche;

    public :

        sdlJeu ();
        ~sdlJeu ();
        void sdlBoucle ();
        void sdlAff ();

}