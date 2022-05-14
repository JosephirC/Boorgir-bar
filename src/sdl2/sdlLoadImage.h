#ifndef _SDL_LOAD_IMAGE_H
#define _SDL_LOAD_IMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "sdlImage.h"

using namespace std;

class loadImage{

    private :

        string nom, chemin;
        unsigned int emplacement, x , y, w, h;

        vector<Image> loaded_im;

    public : 

        loadImage();

        loadImage(const string & nomIm, const unsigned int & eIm, const string & cheminIm, const unsigned int & xIm, const unsigned int & yIm, const unsigned int & wIm, const unsigned int & hIm);

        void chargerTxtImages(const string & filenameIm);

        vector<Image> getLoadedImage() const;
};

#endif