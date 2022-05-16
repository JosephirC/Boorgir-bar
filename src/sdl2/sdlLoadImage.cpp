#include "sdlLoadImage.h"
#include "sdlImage.h"
#include <fstream>
#include <vector>
#include <iostream> 

using namespace std;

/** < @brief Constructeur de loadImgSdl */
loadImage::loadImage(){

}

/** < @brief Constructeur de loadImgSdl */
loadImage::loadImage(const string & nomIm, const unsigned int & eIm, const string & cheminIm, const unsigned int & xIm, const unsigned int & yIm, const unsigned int & wIm, const unsigned int & hIm){
    nom = nomIm; 
    chemin = cheminIm;
    emplacement = eIm;
    x = xIm;
    y = yIm;
    w = wIm;
    h = hIm;
}

/** < @brief Charge le fichier txt contenant les donnees de l'image */
void loadImage::chargerTxtImages(const string & filenameIm){
    ifstream fileIm(filenameIm.c_str());
    string nom, chemin;
    unsigned int emplacement, x , y, w, h, c;

    if(fileIm.is_open()){
        string line;
		getline(fileIm, line);
        while(fileIm >> nom >> emplacement >>  chemin >> x >> y >> w >> h >> c){
            Image ima(nom, emplacement, chemin, x , y, w, h, c);
            loaded_im.push_back(ima);
        }
        fileIm.close();
    }
    
    else
        cout << "Failed to open file..." << endl;
}

/** < @brief Accesseur : recupere l'image charge */
vector<Image> loadImage::getLoadedImage() const{
    return loaded_im;
}

