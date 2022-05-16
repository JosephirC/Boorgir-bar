#include <iostream> 
#include "sdlJeu.h"
#include "sdlImage.h"
#include "sdlLoadImage.h"

using namespace std;

/** < @brief Fonction principale de SDL */
int main()
{
    srand(time(NULL));
    sdlJeu sj;
    sj.sdlBoucle();

    Image i;
    vector<Image> im;
    //i.chargerImage(im, )

    //for(unsigned int i =0 i<)

    return 0;
}