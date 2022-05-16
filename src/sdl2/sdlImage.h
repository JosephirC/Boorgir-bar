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

        /** < @param surface surface de l'image */
        SDL_Surface * surface;
        /** < @param texture texture de l'image */
        SDL_Texture * texture;
        /** < @param has_changed l'image a change */
        bool has_changed;
        /** < @param nom nom de l'image
        * @param chemin chemin de l'image
        */
        string nom, chemin;
        /** < @param x position x
        * @param y position y
        * @param w laregur
        * @param h hauteur 
        */
        int x , y, w, h;
        /** < @param emplacement emplacement de l'image
        * @param numCase numero de la case */
        unsigned int emplacement, numCase;
        /** < @param dimx dimension x de l'image
        * @param dim y dimension y de l'image */
        int dimx, dimy;

    public : 

        /** < @brief Constructeur de sdlImage  */
        Image();

        /** < @brief Constructeur de sdlImage  */
        Image(const string & nomIm, const unsigned int & eIm, const string & cheminIm, const unsigned int & xIm, const unsigned int & yIm, const unsigned int & wIm, const unsigned int & hIm, const unsigned int & cIm);
        
        /** < @brief Charge du fichier */
        void loadFromFile(const char * filename, SDL_Renderer * renderer);

	    /** < @brief Charge de la surface actuelle  */
        void loadFromCurrentSurface(SDL_Renderer * renderer);

        /** < @brief  Dessine l'image */
        void draw(SDL_Renderer * renderer, int x, int y, int w = -1, int h = -1);

        /** < @brief Accesseur : recupere la texture */
        SDL_Texture * getTexture() const;

        //static void chargerTxtImages(vector<Image> & vecIm, const string & filenameIm); // cherger image dans un tableau dynamique;

        /** < @brief Mutateur : modifie la surface */
        void setSurface(SDL_Surface * surf);
        /** < @brief Mutateur : modifie le nom */
        void setNom(const string & nomIm); // peut etre inutile
        /** < @brief Mutateur : modifie le chemin */
        void setChemin(const string & cheminIm); // peut etre inutile
        /** < @brief Mutateur : modifie l'emplacement */
        void setEmplacement(const unsigned int & e); // peut etre inutile
        /** < @brief Mutateur : modifie X */
        void setX(const int & xI);
        /** < @brief Mutateur : modifie Y */
        void setY(const int & yI);
        /** < @brief Mutateur : modifie W */
        void setW(const int & wI);
        /** < @brief Mutateur : modifie H */
        void setH(const int & hI);
        /** < @brief Mutateur : modifie la case */
        void setCase(const unsigned int & caseIm);
        /** < @brief Mutateur : modifie la dimension x */
        void setDimX(const int & x);
        /** < @brief Mutateur : modifie la dimension y */
        void setDimY(const int & y);
        /** < @brief Accesseur : recupere le nom */
        string getNom() const;
        /** < @brief Accesseur : recupere le chemin */
        string getChemin() const;
        /** < @brief Accesseur : recupere l'emplacement */
        unsigned int getEmplacement() const;
        /** < @brief Accesseur : recupere X */
        int getX() const;
        /** < @brief Accesseur : recupere Y */
        int getY() const;
        /** < @brief Accesseur : recupere W */
        int getW() const;
        /** < @brief Accesseur : recupere H  */
        int getH() const;
        /** < @brief Accesseur : recupere la case */
        unsigned int getCase() const;
        /** < @brief Accesseur : recupere la dimension x */
        int getDimX() const;
        /** < @brief Accesseur : recupere la dimension y */
        int getDimY() const;
};

#endif