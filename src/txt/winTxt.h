#ifndef WINTXT_H
#define WINTXT_H

/** < @brief une fenetre texte est un tableau 2D de caracteres */
class WinTXT
{
private:

    /** < @param dimx largeur */
    int dimx;       
    /** < @param dimy hauteur */
    int dimy;      
    /** < @param win stocke le contenu de la fenetre dans un tableau 1D mais on y accede en 2D */
    char* win;      

public:

    WinTXT ();
    void clear (char c=' ');
    void print (int x, int y, char c);
    void print (int x, int y, char* c);
    void draw (int x=0, int y=0);
    void pause();
    /** < @brief Accesseur : recupere un caractere si une touche a ete pressee */
    char getCh();

};

void termClear ();

#endif
