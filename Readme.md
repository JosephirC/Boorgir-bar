| EL-SAIDI Yara P2018561 | HANNA Sandrine P1906670 | ABIDA Youssef P2024398 |
| -----------------------|--------------------|------------------|

## Le contenu du projet :

Apr�s tant de recherche notre projet est enfin pr�t ! Il contient :
* Une documentation doxyfile pour pouvoir lire en details les utilit�s des fonctions.
* Le code Jeu contient: 
    - Constructeur/Destructeur Jeu
    - Tous les chargement des fichiers txt en rapport avec le core du code:Ingredients,Recette,Carte
    - Accesseur et mutateur des parametres en prive
    - Procedures qui cree les clients, efface les recettes et les accompagnement une fois servi,genere de nouveau Client une fois qu'ils sont tous servi,calcule l'argent collecte durant le jeu.

* Le code Client contient:
    - Un Constructeur/Destructeur
    - Accesseur et mutateur des parametres en prive
    - Procedure qui charge une commende aleatoire dans le vecteur prive com et une autre qui calcule prix que doit payer le client dans l'int prixTot
    - Finalement erase qui efface 
* Le code Commade contient:
    - Un Constructeur/Destructeur
    - Accesseur et mutateur des parametres en prive
    

* Les 3 main :
    - mainSdl : compile le jeu avec SDL.
    - mainTxt : compile le jeu en Txt.
    - main : fait le test de regression.



## Comment compiler et executer le programme :

Pour compiler le programme il suffit d'utiliser le makefile � la racine avec la commande " make " qui genere dans bin les ex�cutables.
* ./bin/mainSdl : compile le jeu avec SDL.
* ./bin/mainTxt : compile le jeu en Txt.
* ./bin/main : fait le test de regression.


## Oranisation des archives :

| repertoire | contenu |
| -----------|----------|
| ./bin | les ex�cutables |
| ./data | les images |
| ./doc | la documentation |
| ./obj | les fichiers "*.o" |
| ./src | le code core (.cpp et .h) |
| ./src/txt | le code affichage console (.cpp et .h)|
| ./src/sdl2 | le code SDL2 (.cpp et .h)|
| . | Makefile et Readme |







