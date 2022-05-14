#include "sdlLoadImage.h"
#include "sdlImage.h"
#include <fstream>
#include <vector>
#include <iostream> 

using namespace std;

loadImage::loadImage(){

}

loadImage::loadImage(const string & nomIm, const unsigned int & eIm, const string & cheminIm, const unsigned int & xIm, const unsigned int & yIm, const unsigned int & wIm, const unsigned int & hIm){
    nom = nomIm; 
    chemin = cheminIm;
    emplacement = eIm;
    x = xIm;
    y = yIm;
    w = wIm;
    h = hIm;
}


void loadImage::chargerTxtImages(const string & filenameIm){
    ifstream fileIm(filenameIm.c_str());
    string nom, chemin;
    unsigned int emplacement, x , y, w, h;

    if(fileIm.is_open()){
        while(fileIm >> nom >> emplacement >>  chemin >> x >> y >> w >> h){
            Image ima(nom, emplacement, chemin, x , y, w, h);
            loaded_im.push_back(ima);
        }
        fileIm.close();
    }
    
    else
        cout << "Failed to open file..." << endl;
}

vector<Image> loadImage::getLoadedImage() const{
    return loaded_im;
}

