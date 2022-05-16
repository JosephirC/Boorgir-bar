#include "sdlImage.h"

#include <cassert>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

// ============= CLASS IMAGE =============== //

/** < @brief Constructeur de sdlImage  */
Image::Image () {
    surface = NULL;
    texture = NULL;
    has_changed = false;
    //chemin = "";
}

/** < @brief Constructeur de sdlImage  */
Image::Image(const string & nomIm, const unsigned int & eIm, const string & cheminIm, const unsigned int & xIm, const unsigned int & yIm, const unsigned int & wIm, const unsigned int & hIm, const unsigned int & cIm){
    surface = NULL;
    texture = NULL;
    has_changed = false;
    nom = nomIm; 
    chemin = cheminIm;
    emplacement = eIm;
    x = xIm;
    y = yIm;
    w = wIm;
    h = hIm;
    numCase = cIm;
}

/** < @brief Charge du fichier */
void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    //cout << "appel" << endl;

    if(surface !=NULL)
    {
        delete surface;
    }
    surface = IMG_Load(filename);
    if (surface == NULL) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == NULL) {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == NULL) {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}

/** < @brief Charge de la surface actuelle  */
void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

/** < @brief  Dessine l'image */
void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(ok == 0);
}

/** < @brief Accesseur : recupere la texture */
SDL_Texture * Image::getTexture() const {
    return texture;
}

/** < @brief Mutateur : modifie la surface */
void Image::setSurface(SDL_Surface * surf) {
    surface = surf;
}

/** < @brief Mutateur : modifie le nom */
void Image::setNom(const string & nomIm){
    nom = nomIm;
}

/** < @brief Mutateur : modifie le chemin */
void Image::setChemin(const string & cheminIm){
    chemin = cheminIm;
}

/** < @brief Mutateur : modifie l'emplacement */
void Image::setEmplacement(const unsigned int & e){
    emplacement = e;
}

/** < @brief Mutateur : modifie X */
void Image::setX(const int & xI){
    x = xI;
}

/** < @brief Mutateur : modifie Y */
void Image::setY(const int & yI){
    y = yI;
}

/** < @brief Mutateur : modifie W */
void Image::setW(const int & wI){
    w = wI;
}

/** < @brief Mutateur : modifie H */
void Image::setH(const int & hI){
    h = hI;
}

/** < @brief Mutateur : modifie la case */
void Image::setCase(const unsigned int & caseIm){
    numCase = caseIm;
}

/** < @brief Mutateur : modifie la dimension x */
void Image::setDimX(const int & x){
    dimx = x;
}

/** < @brief Mutateur : modifie la dimension y */
void Image::setDimY(const int & y){
    dimy = y;
}

/** < @brief Accesseur : recupere le nom */
string Image::getNom() const{
    return nom;
}

/** < @brief Accesseur : recupere le chemin */
string Image::getChemin() const{
    return chemin;
}

/** < @brief Accesseur : recupere l'emplacement */
unsigned int Image::getEmplacement() const{
    return emplacement;
}

/** < @brief Accesseur : recupere X */
int Image::getX() const{
    return x;
}

/** < @brief Accesseur : recupere Y */
int Image::getY() const{
    return y;
}

/** < @brief Accesseur : recupere W */
int Image::getW() const{
    return w;
}

/** < @brief Accesseur : recupere H  */
int Image::getH() const{
    return h;
}

/** < @brief Accesseur : recupere la case */
unsigned int Image::getCase() const{
    return numCase;
}

/** < @brief Accesseur : recupere la dimension x */
int Image::getDimX() const{
    return dimx;
}

/** < @brief Accesseur : recupere la dimension y */
int Image::getDimY() const{
    return dimy;
}