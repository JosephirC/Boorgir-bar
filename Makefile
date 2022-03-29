all: bin/main

bin/main: obj/main.o obj/Jeu.o obj/Recette.o obj/Ingredient.o obj/Commande.o obj/Menu.o obj/Objectif.o obj/Temps.o
	g++ obj/main.o obj/Ingredient.o obj/Recette.o obj/Jeu.o obj/Commande.o obj/Menu.o obj/Objectif.o obj/Temps.o -o bin/main

obj/main.o: src/main.cpp src/Jeu.h src/Client.h src/Ingredient.h src/Recette.h
	g++ -ggdb -Wall -c src/main.cpp -o obj/main.o

obj/Jeu.o: src/Jeu.cpp src/Jeu.h src/Ingredient.h src/Recette.h src/Temps.h src/Client.h
	g++ -ggdb -Wall -c src/Jeu.cpp -o obj/Jeu.o

obj/Recette.o: src/Recette.cpp src/Recette.h src/Ingredient.h
	g++ -ggdb -Wall -c src/Recette.cpp -o obj/Recette.o

obj/Ingredient.o: src/Ingredient.cpp src/Ingredient.h
	g++ -ggdb -Wall -c src/Ingredient.cpp -o obj/Ingredient.o

obj/Commande.o: src/Commande.cpp src/Commande.h src/Recette.h
	g++ -ggdb -Wall -c src/Commande.cpp -o obj/Commande.o

obj/Menu.o: src/Menu.cpp src/Menu.h
	g++ -ggdb -Wall -c src/Menu.cpp -o obj/Menu.o

obj/Objectif.o: src/Objectif.cpp src/Objectif.h src/Temps.h
	g++ -ggdb -Wall -c src/Objectif.cpp -o obj/Objectif.o

obj/Temps.o: src/Temps.cpp src/Temps.h
	g++ -ggdb -Wall -c src/Temps.cpp -o obj/Temps.o

clean:
	rm obj/*.o

veryclean: clean 
	rm *.out

