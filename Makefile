DIR_SDL = -I /usr/include/SDL2
SDL_LIB = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

all: bin/main bin/mainTxt bin/mainSdl

bin/mainSdl: obj/mainSdl.o obj/Jeu.o obj/Recette.o obj/Ingredient.o obj/Commande.o obj/Client.o obj/Objectif.o obj/Temps.o obj/sdlJeu.o obj/sdlImage.o
	g++ obj/mainSdl.o obj/Jeu.o obj/Recette.o obj/Ingredient.o obj/Commande.o obj/Client.o obj/Objectif.o obj/Temps.o obj/sdlJeu.o obj/sdlImage.o -o bin/mainSdl $(SDL_LIB)

obj/mainSdl.o: src/sdl2/mainSdl.cpp src/sdl2/sdlJeu.h src/sdl2/sdlImage.h
	g++ -ggdb -Wall -c src/sdl2/mainSdl.cpp -o obj/mainSdl.o $(DIR_SDL)

obj/sdlJeu.o: src/sdl2/sdlJeu.cpp  src/sdl2/sdlJeu.h src/sdl2/sdlImage.h
	g++ -ggdb -Wall -c src/sdl2/sdlJeu.cpp -o obj/sdlJeu.o $(DIR_SDL)

obj/sdlImage.o: src/sdl2/sdlImage.cpp src/sdl2/sdlImage.h
	g++ -ggdb -Wall -c src/sdl2/sdlImage.cpp -o obj/sdlImage.o $(DIR_SDL)

bin/mainTxt: obj/mainTxt.o obj/Jeu.o obj/Recette.o obj/Ingredient.o obj/Commande.o obj/Client.o obj/Objectif.o obj/Temps.o obj/winTxt.o obj/txtJeu.o
	g++ obj/mainTxt.o obj/Ingredient.o obj/Recette.o obj/Jeu.o obj/Commande.o obj/Client.o obj/Objectif.o obj/Temps.o obj/winTxt.o obj/txtJeu.o -o bin/mainTxt $(SDL_LIB)

obj/mainTxt.o: src/txt/mainTxt.cpp src/txt/winTxt.h src/txt/txtJeu.h
	g++ -ggdb -Wall -c src/txt/mainTxt.cpp -o obj/mainTxt.o $(DIR_SDL)

obj/winTxt.o: src/txt/winTxt.cpp src/txt/winTxt.h
	g++ -ggdb -Wall -c src/txt/winTxt.cpp -o obj/winTxt.o $(DIR_SDL)

obj/txtJeu.o: src/txt/txtJeu.cpp src/txt/txtJeu.h
	g++ -ggdb -Wall -c src/txt/txtJeu.cpp -o obj/txtJeu.o $(DIR_SDL)

bin/main: obj/main.o obj/Jeu.o obj/Recette.o obj/Ingredient.o obj/Commande.o obj/Client.o obj/Objectif.o obj/Temps.o
	g++ obj/main.o obj/Ingredient.o obj/Recette.o obj/Jeu.o obj/Commande.o obj/Client.o obj/Objectif.o obj/Temps.o -o bin/main $(SDL_LIB)

obj/main.o: src/main.cpp src/Jeu.h src/Client.h src/Ingredient.h src/Recette.h
	g++ -ggdb -Wall -c src/main.cpp -o obj/main.o $(DIR_SDL)

obj/Jeu.o: src/Jeu.cpp src/Jeu.h src/Ingredient.h src/Recette.h src/Temps.h src/Client.h
	g++ -ggdb -Wall -c src/Jeu.cpp -o obj/Jeu.o $(DIR_SDL)

obj/Recette.o: src/Recette.cpp src/Recette.h src/Ingredient.h
	g++ -ggdb -Wall -c src/Recette.cpp -o obj/Recette.o $(DIR_SDL)

obj/Ingredient.o: src/Ingredient.cpp src/Ingredient.h
	g++ -ggdb -Wall -c src/Ingredient.cpp -o obj/Ingredient.o $(DIR_SDL)

obj/Commande.o: src/Commande.cpp src/Commande.h src/Recette.h
	g++ -ggdb -Wall -c src/Commande.cpp -o obj/Commande.o $(DIR_SDL)

obj/Client.o: src/Client.cpp src/Client.h src/Commande.h
	g++ -ggdb -Wall -c src/Client.cpp -o obj/Client.o $(DIR_SDL)


obj/Objectif.o: src/Objectif.cpp src/Objectif.h src/Temps.h
	g++ -ggdb -Wall -c src/Objectif.cpp -o obj/Objectif.o $(DIR_SDL)

obj/Temps.o: src/Temps.cpp src/Temps.h
	g++ -ggdb -Wall -c src/Temps.cpp -o obj/Temps.o $(DIR_SDL)

clean:
	rm obj/*.o
	rm bin/*

veryclean: clean 
	rm *.out

