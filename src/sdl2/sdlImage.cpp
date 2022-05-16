#include "sdlImage.h"

#include <cassert>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

// ============= CLASS IMAGE =============== //

Image::Image () {
    surface = NULL;
    texture = NULL;
    has_changed = false;
    //chemin = "";
}


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

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
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

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

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

SDL_Texture * Image::getTexture() const {
    return texture;
}


void Image::setSurface(SDL_Surface * surf) {
    surface = surf;
}

void Image::setNom(const string & nomIm){
    nom = nomIm;
}

void Image::setChemin(const string & cheminIm){
    chemin = cheminIm;
}

void Image::setEmplacement(const unsigned int & e){
    emplacement = e;
}

void Image::setX(const int & xI){
    x = xI;
}

void Image::setY(const int & yI){
    y = yI;
}

void Image::setW(const int & wI){
    w = wI;
}

void Image::setH(const int & hI){
    h = hI;
}

void Image::setCase(const unsigned int & caseIm){
    numCase = caseIm;
}

void Image::setDimX(const int & x){
    dimx = x;
}

void Image::setDimY(const int & y){
    dimy = y;
}

string Image::getNom() const{
    return nom;
}

string Image::getChemin() const{
    return chemin;
}

unsigned int Image::getEmplacement() const{
    return emplacement;
}

int Image::getX() const{
    return x;
}

int Image::getY() const{
    return y;
}

int Image::getW() const{
    return w;
}

int Image::getH() const{
    return h;
}

unsigned int Image::getCase() const{
    return numCase;
}

int Image::getDimX() const{
    return dimx;
}

int Image::getDimY() const{
    return dimy;
}