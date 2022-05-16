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

	    /** < @param nom Chaine de caractere
	    * @param chemin Chaine de caractere */
        string nom, chemin;
        /** < @param emplacement : entier naturel
        * @param x Entier naturel
        * @param y Entier naturel
        * @param w Entier naturel
        * @param h Entier naturel */      
        unsigned int emplacement, x , y, w, h;

	    /** < @param loaded_im Vecteur Image */
        vector<Image> loaded_im;

    public : 

	    /** < @brief Constructeur de loadImgSdl */
        loadImage();
	    /** < @brief Constructeur de loadImgSdl */
        loadImage(const string & nomIm, const unsigned int & eIm, const string & cheminIm, const unsigned int & xIm, const unsigned int & yIm, const unsigned int & wIm, const unsigned int & hIm);
        /** < @brief Charge le fichier txt contenant les donnees de l'image */
        void chargerTxtImages(const string & filenameIm);
	    /** < @brief Accesseur : recupere l'image charge */
        vector<Image> getLoadedImage() const;
};

#endif