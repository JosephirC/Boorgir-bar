#ifndef _SDL_IMAGE_H
#define _SDL_IMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Image{

    private :

        SDL_Surface * surface;
        SDL_Texture * texture;
        bool has_changed;
        string nom, chemin;
        int x , y, w, h;
        unsigned int emplacement, numCase;
        int dimx, dimy;

    public : 

        Image();

        Image(const string & nomIm, const unsigned int & eIm, const string & cheminIm, const unsigned int & xIm, const unsigned int & yIm, const unsigned int & wIm, const unsigned int & hIm, const unsigned int & cIm);

        void loadFromFile(const char * filename, SDL_Renderer * renderer);

        void loadFromCurrentSurface(SDL_Renderer * renderer);

        void draw(SDL_Renderer * renderer, int x, int y, int w = -1, int h = -1);

        SDL_Texture * getTexture() const;

        //static void chargerTxtImages(vector<Image> & vecIm, const string & filenameIm); // cherger image dans un tableau dynamique;

        void setSurface(SDL_Surface * surf);

        void setNom(const string & nomIm); // peut etre inutile

        void setChemin(const string & cheminIm); // peut etre inutile

        void setEmplacement(const unsigned int & e); // peut etre inutile

        void setX(const int & xI);

        void setY(const int & yI);

        void setW(const int & wI);

        void setH(const int & hI);

        void setCase(const unsigned int & caseIm);

        void setDimX(const int & x);

        void setDimY(const int & y);

        string getNom() const;

        string getChemin() const;

        unsigned int getEmplacement() const;

        int getX() const;

        int getY() const;

        int getW() const;

        int getH() const;

        unsigned int getCase() const;

        int getDimX() const;

        int getDimY() const;
};

#endif