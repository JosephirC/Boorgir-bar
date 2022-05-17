#ifndef _SDL_JEU_H
#define _SDL_JEU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <vector>
#include "../Jeu.h"
#include "../Client.h"
#include "../Commande.h"
#include "sdlImage.h"
#include "sdlLoadImage.h"

class sdlJeu {

    private : 

        /** < @param jeu classe Jeu */
        Jeu jeu;

        /** < @param window Fenetre de SDL */
        SDL_Window * window;
        /** < @param renderer Charge la fenetre graphique  */
        SDL_Renderer * renderer;

        /** < @param font Calligraphie du texte */
        TTF_Font * font;
        /** < @param font_im Image du texte */
        Image font_im;
        /** < @param font_color Couleur du texte */
        SDL_Color font_color;


        Mix_Chunk * sound;
        bool withSound;


        /** < @param background Fond d'ecran de l'image */
        Image background;
        Image Argent;
        Image Time;
        Image Plat;

        /** < @param nbrIngJ Nombre d'ingredients  */
        unsigned int nbrIngJ;

        vector<Image> im;
        vector<Image> imCom0;
        vector<Image> imCom1;
        vector<Image> imCom2;
        vector<Image> imCom3;
        
        loadImage loadImg;

        Image newImage;
        Image image0, image1, image2, image3;

        /** < @param mx coordonnee x de la souris
        * @param my coordonnee y de la souris
        */
        int mx, my; 

        /** < @param nbrClientServi Nombre de clients servies */
        unsigned int nbrClientServi;
        unsigned int zero, one, two, three;

        /** < @param aServir Nombre de client a servir */
        string aServir;
        string isExtra;
        /** < @param idService identifiant du Service */
        unsigned int idService;

    public :

        sdlJeu ();
        ~sdlJeu ();
       
        void sdlAff ();
        
        void sdlLoadImgFile();

       // void MenuPrincipal(Jeu & Game);
       // bool afficherAccueil();
       // void AttendreClic(int & x, int & y);
       // void RenduImage (SDL_Renderer * renderer, char* nomImage, int x, int y, double angle, SDL_RendererFlip flip);

        //vector<Image> getImageVec() const;

        void setImCons(Image imCons);

        unsigned int getNbrIngJ() const;

        //void setNewImg(const string & nIm, const unsigned int & eIm, const string & cIm, const unsigned int & xIm, const unsigned int & yIm, const unsigned int & wIm, const unsigned int & hIm);

        void setNewImg(Image i);

        void setIm0(Image i0);

        void setIm1(Image i1);

        void setIm2(Image i2);

        void setIm3(Image i3);

        void mousePress(SDL_MouseButtonEvent& b);

        void drawImgClient();

        void drawImgPlat();

        void chargeInfoClient();

        void loadImgCommande();

        void drawImgCommande();

        void servirClient();

        void viderExtra(unsigned int & i);

        void choisirExtra(SDL_MouseButtonEvent& b);

        void effacerTableImg(unsigned int & i);

        void viderTable();

        void rempliClient();

        void sdlBoucle ();

};

#endif