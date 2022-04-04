#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"

#include "../Jeu.h"

void txtAff(WinTXT & win, const Jeu & jeu) {
	
}

void txtBoucle (Jeu & jeu) {
	
	bool ok = true;
	
	do {
	    //txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		

	} while (ok);

}
